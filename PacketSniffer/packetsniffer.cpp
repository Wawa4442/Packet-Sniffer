#include "packetsniffer.h"
#include "ui_packetsniffer.h"
#include <QTextEdit>  //libreria para el QtextEdit
#include <QRegularExpression> //Libreria para la captura de datos en el QTextEdit por filas

packetSniffer *sniffer=nullptr;  //Apuntador generico de la clase packetSniffer

QString dispositivo;  //Cadena que almacena en Qstring el dispositivo que elija el usuario
int link_hdr_length = 0;
// Contador de paquetes
int packet_counter = 0;
QStandardItemModel *model; //Modelo global de la table view
QHash<int, QString> rawDataMap;
/*
pcap_t* capdev;
int link_hdr_length = 0;
int packet_counter = 0;*/

captura::captura(QObject *parrent, pcap_t *capdev) : QThread(parrent), capdev(capdev){}

void captura::run() {

    // Asegúrate de que capdev esté correctamente inicializado antes de llamar a pcap_loop
    if (this->capdev == nullptr) {
        qDebug() << "Error, capdev no está inicializado correctamente";
        return;
    }

    // llamamos a pcap_loop de forma que nos aseguramos que podamos cachar algun posible error grave
    int result = pcap_loop(this->capdev, 0, callback_function, reinterpret_cast<u_char*>(this));
    if (result == -1) {
        qDebug() << "Error en pcap_loop: " << pcap_geterr(this->capdev);
    } else if (result == -2) {
        qDebug() << "Captura detenida correctamente.";
    } else {
        qDebug() << "Captura finalizada correctamente.";
    }
}

packetSniffer::packetSniffer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::packetSniffer)
{
    ui->setupUi(this);
    this->show();

    sniffer = this;

    // Creaamos el modelo y asignamos el puntero de la tabla
    tableModel = new QStandardItemModel(this);
    tableView = ui->tableView;

    // Configuraramos los títulos de las columnas para que sea acorde a los datos que mandamos
    tableModel->setHorizontalHeaderLabels({"ID Packet","Time","Protocol","Source IP","Destination IP","TTL","Lenght", "Extra Info"});
    tableView->setModel(tableModel);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tableView->horizontalHeader()->setMinimumSectionSize(80);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->menuBar->setStyleSheet("background-color: rgb(20, 35, 25); color: rgb(120, 176, 137);");
    ui->menuCaptura->setStyleSheet("color: rgb(120, 176, 137);");

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    rawDataTextEdit = ui->rawDataTextEdit;
    rawHexDataTextEdit = ui->rawHexDataTextEdit;

}

packetSniffer::~packetSniffer()
{
    pcap_close(capdev);
    rawDataMap.clear();
    delete ui;
}

void packetSniffer::start(/*pcap_if_t* device*/)
{
    this->show();
}

void packetSniffer::selected_Interface(const QString &selectedInterface){

    dispositivo = selectedInterface;
    //Manda a la funcion de start para que comience el codigo
    this->start();


}

void packetSniffer::on_startButton_clicked() //Funcion del boton de start
{
    ui->stopButton->setEnabled(true);
    ui->startButton->setEnabled(false);
    ui->actionFiltros->setEnabled(false);
    ui->actionExportar_captura->setEnabled(false);
    ui->menuCaptura->setStyleSheet("color: rgb(99, 110, 99);");
    ui->startButton->setStyleSheet("background-color: rgb(21, 53, 38); color: rgb(100, 100, 100);");
    ui->stopButton->setStyleSheet("background-color: rgb(47, 121, 86); color: rgb(0, 0, 0);");

    if (tableModel) {
        tableModel->removeRows(0, tableModel->rowCount());
        rawDataMap.clear();
        packet_counter = 0;
    }


    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_if_t *alldevs, *device;
    int device_number, i = 0;

    // Encuentra todas las interfaces de red disponibles
    if (pcap_findalldevs(&alldevs, error_buffer) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", error_buffer);
    }

    for (device = alldevs; device != NULL; device = device->next) {
        printf("%d. %s", ++i, device->name);
        if (device->description);
    }

    // Recorre la lista de interfaces de red
    for (device = alldevs; device != nullptr; device = device->next) {
        // Compara el nombre de la interfaz actual con el nombre seleccionado (en selectedInterface)
        if (QString(device->name) == dispositivo) {
            // Si coinciden, hemos encontrado la interfaz
            //qDebug() << "Using device: " << device->name;
            this->dispositoElegido = device;
            break;
        }
    }

    //qDebug() << "Using device: " << device->name;

    // Abre el dispositivo elegido
    pcap_t* capdev = pcap_open_live(device->name, BUFSIZ, 1, 1000, error_buffer);
    if (capdev == NULL) {
        fprintf(stderr, "Error opening device: %s\n", error_buffer);
        pcap_freealldevs(alldevs);
        return;  // sale si no puede abrir el dispostivo
    }

    // Obtén el tipo de enlace del dispositivo
    int link_hdr_type = pcap_datalink(capdev);
    switch (link_hdr_type) {
    case DLT_NULL:
        link_hdr_length = 4;
        break;
    case DLT_EN10MB:
        link_hdr_length = 14;
        break;
    default:
        link_hdr_length = 0;
    }

    if(false/*isFiltro*/)
    {
        struct bpf_program filter;
        const char *filter_exp = filtroStr.toStdString().c_str();
        bpf_u_int32 netmask = 0xFFFFFF;

        if (pcap_compile(capdev, &filter, filter_exp, 0, netmask) == -1) {
            fprintf(stderr, "Error in pcap_compile: %s\n", pcap_geterr(capdev));
            pcap_close(capdev);
            return;
        }

        if (pcap_setfilter(capdev, &filter) == -1) {
            fprintf(stderr, "Error in pcap_setfilter: %s\n", pcap_geterr(capdev));
            pcap_close(capdev);
            return;
        }

    }




    this->HiloCaptura(capdev);
}

void captura::callback_function(u_char *user, const struct pcap_pkthdr *pkthdr, const u_char *packet) {
    const u_char* packetd_ptr = packet;
    packetd_ptr += link_hdr_length;

    captura* self = reinterpret_cast<captura*>(user);


    struct iphdr* ip_hdr = (struct iphdr*)(packetd_ptr);

    // Validamos el tamaño del encabezado IP para evitar errores
    int ip_header_size = ip_hdr->ihl * 4;
    if (ip_header_size < 20) {
        qDebug() << "Encabezado IP inválido.";
        return;
    }
    packetd_ptr += ip_header_size;

    // Definiimos las direcciones IP como char* para convertirlas a QString
    char packet_srcip[INET_ADDRSTRLEN];
    char packet_dstip[INET_ADDRSTRLEN];

    // Convertimos las direcciones IP a cadenas legibles usando inet_ntop
    if (!inet_ntop(AF_INET, &(ip_hdr->saddr), packet_srcip, INET_ADDRSTRLEN) ||
        !inet_ntop(AF_INET, &(ip_hdr->daddr), packet_dstip, INET_ADDRSTRLEN)) {
        qDebug() << "Error al leer las direcciones IP.";
        return;
    }

    // Recuperamos los datos del paquete como el ID, TTL y protocolo
    int packet_id = ntohs(ip_hdr->id);
    int packet_ttl = ip_hdr->ttl;
    int packet_protocol = ip_hdr->protocol;

    // Convertimos las IPs a QString antes de emitir
    QString srcIP = QString::fromLatin1(packet_srcip);
    QString dstIP = QString::fromLatin1(packet_dstip);
    QString lengthStr = QString::number(pkthdr->len);

    // Emitir las direcciones IP en formato QString
    emit self->capturaPacket(packet_id, packet_ttl, packet_protocol, srcIP, dstIP, packetd_ptr, lengthStr, ip_hdr, user, packet, self);
}

void packetSniffer::HiloCaptura(pcap_t* capdev) {
    this->captura1 = new captura(this, capdev);

    // Conectar la señal del hilo a la función en el hilo principal
    connect(this->captura1, &captura::capturaPacket, this, &packetSniffer::agregarPaquete, Qt::QueuedConnection);

    this->captura1->start();
}

void packetSniffer::agregarPaquete(int packet_id, int packet_ttl, int packet_protocol,
                                   const QString& packet_srcip, const QString& packet_dstip,
                                   const u_char* packetd_ptr, const QString& lengthStr, struct iphdr* ip_hdr
                                   , u_char *user, const u_char* packet, captura* self) {


    if (!tableModel) {
        qDebug() << "Error: el modelo no está inicializado.";
        return;
    }
    /*
    qDebug() << "------- Recibiendo Paquete -------";
    qDebug() << "Packet ID:" << packet_id;
    qDebug() << "TTL:" << packet_ttl;
    qDebug() << "Protocol:" << packet_protocol;
    qDebug() << "Source IP:" << packet_srcip;
    qDebug() << "Destination IP:" << packet_dstip;*/

    // Obtener el tiempo actual con alta precisión
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();

    // Obtener segundos y nanosegundos
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
    auto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(duration - seconds);

    // Convertir a QTime (hora actual)
    QTime horaActual = QTime::currentTime();

    // Formatear la salida
    std::ostringstream timeStr;
    timeStr << horaActual.toString("HH:mm:ss").toStdString()
            << "." << std::setfill('0') << std::setw(7) << nanoseconds.count();

    QString packetIDStr = QString::number(packet_id);
    QString packetTTLStr = QString::number(packet_ttl);

    //Obtener los primeros 64 bytes del paquete para mostrar como datos crudos
    QByteArray rawData = QByteArray::fromRawData(reinterpret_cast<const char*>(packet), 64);

    // Mostrar la información cruda en el QTextEdit
    if (rawDataTextEdit) {
        rawDataTextEdit->clear();
        rawDataTextEdit->append("-----------------------------------------------------");
        rawDataTextEdit->append("Raw Data (first 64 bytes): " + rawData.toHex());
        rawDataTextEdit->append("-----------------------------------------------------");
    }

    if (rawHexDataTextEdit){
        rawHexDataTextEdit->clear();
        rawHexDataTextEdit->append("-----------------------------------------------------");
        rawHexDataTextEdit->append("Packet ID: " + packetIDStr);
        rawHexDataTextEdit->append("Source IP: " + packet_srcip);
        rawHexDataTextEdit->append("Destination IP: " + packet_dstip);
        rawHexDataTextEdit->append("Protocol: " + QString::number(packet_protocol));
        rawHexDataTextEdit->append("TTL: " + packetTTLStr);
        rawHexDataTextEdit->append("-----------------------------------------------------");
    }

    // Aquí es donde manejas los protocolos TCP/UDP/ICMP (puedes mantener esta parte igual que antes)
    // Asegúrate de que el paquete se añade correctamente al modelo de la tabla.

    /*
     *
    QList<QStandardItem*> rowItems;
    rowItems.append(new QStandardItem(packetIDStr));
    rowItems.append(new QStandardItem(QString::number(packet_protocol)));
    rowItems.append(new QStandardItem(packet_srcip));
    rowItems.append(new QStandardItem(packet_dstip));
    rowItems.append(new QStandardItem(packetTTLStr));*/


    switch (packet_protocol) {
    case IPPROTO_TCP: {
        struct tcphdr* tcp_header = (struct tcphdr*)packetd_ptr;
        if(tcp_header) {
            int src_port = ntohs(tcp_header->source);
            int dst_port = ntohs(tcp_header->dest);

            QString srcPortStr = "Src port: " + QString::number(src_port);
            QString dstPortStr = "  Dst port: " + QString::number(dst_port);
            //QString packetProtocolStr = QString::number(packet_protocol);
            QString extraInfo = srcPortStr + dstPortStr;

            insertData(packetIDStr,QString::fromStdString(timeStr.str()),"TCP",packet_srcip,packet_dstip
                                ,packetTTLStr,lengthStr,extraInfo);
            /*
            qDebug() << "TCP Source Port:" << src_port;
            qDebug() << "TCP Destination Port:" << dst_port;

            rowItems.append(new QStandardItem(QString::number(src_port)));
            rowItems.append(new QStandardItem(QString::number(dst_port)));*/
        }
        break;
    }
    case IPPROTO_UDP: {
        struct udphdr* udp_header = (struct udphdr*)packetd_ptr;
        if(udp_header) {
            int src_port = ntohs(udp_header->source);
            int dst_port = ntohs(udp_header->dest);

            QString srcPortStr = "Src port: " + QString::number(src_port);
            QString dstPortStr = "  Dst port: " + QString::number(dst_port);
            //QString packetProtocolStr = QString::number(packet_protocol);
            QString extraInfo = srcPortStr + dstPortStr;

            insertData(packetIDStr,QString::fromStdString(timeStr.str()),"UDP",packet_srcip,packet_dstip
                                ,packetTTLStr,lengthStr,extraInfo);
            /*
            qDebug() << "UDP Source Port:" << src_port;
            qDebug() << "UDP Destination Port:" << dst_port;

            rowItems.append(new QStandardItem(QString::number(src_port)));
            rowItems.append(new QStandardItem(QString::number(dst_port)));*/
        }
        break;
    }
    case IPPROTO_ICMP: {
        struct icmp_hdr* icmp_header = (struct icmp_hdr*)packetd_ptr;
        if (icmp_header) {

            QString typeStr = "Type: " + QString::number(icmp_header->type);
            QString codeStr = "  Code: " + QString::number(icmp_header->code);
            //QString packetProtocolStr = QString::number(packet_protocol);
            QString extraInfo = typeStr + codeStr;

            insertData(packetIDStr,QString::fromStdString(timeStr.str()),"ICMP",packet_srcip,packet_dstip
                                ,packetTTLStr,lengthStr,extraInfo);
            /*
            qDebug() << "ICMP Type:" << icmp_header->type;
            qDebug() << "ICMP Code:" << icmp_header->code;

            rowItems.append(new QStandardItem(QString::number(icmp_header->type)));
            rowItems.append(new QStandardItem(QString::number(icmp_header->code)));*/
        }
        break;
    }
    default:
        QString packetProtocolStr = "UNKNOWN: " + QString::number(packet_protocol);

        insertData(packetIDStr,QString::fromStdString(timeStr.str()),packetProtocolStr,packet_srcip,packet_dstip
                            ,packetTTLStr,lengthStr,"");
        /*
        qDebug() << "Protocolo desconocido o sin soporte";
        rowItems.append(new QStandardItem("N/A"));
        rowItems.append(new QStandardItem("N/A"));*/
        break;
    }

    // Imprimir todos los datos de rowItems
    /*
    qDebug() << "Datos de la fila antes de añadir:";
    for (const auto& item : rowItems) {
        qDebug() << item->text();
    }*/

    // Añadir la fila al modelo
    //tableModel->appendRow(rowItems);
    //qDebug() << "Fila añadida al modelo.";

    rawDataMap.insert(packet_counter++, obtenerContenidoRaw(packetd_ptr,lengthStr.toInt()));
}

void packetSniffer::on_stopButton_clicked()
{
    ui->stopButton->setEnabled(false);
    ui->startButton->setEnabled(true);
    ui->actionFiltros->setEnabled(true);
    ui->actionExportar_captura->setEnabled(true);
    ui->menuCaptura->setStyleSheet("color: rgb(120, 176, 137);");
    ui->stopButton->setStyleSheet("background-color: rgb(21, 53, 38); color: rgb(100, 100, 100);");
    ui->startButton->setStyleSheet("background-color: rgb(47, 121, 86); color: rgb(0, 0, 0);");

    this->captura1->terminate();
    //delete(this);
}


void packetSniffer::on_actionFiltros_triggered()
{
    filtersDialog *ventanaFiltro = new filtersDialog();
    ventanaFiltro->exec();
    isFiltro = ventanaFiltro->isFiltro;
    filtroStr = ventanaFiltro->filtroStr;
    qDebug() << isFiltro;
    qDebug() << filtroStr.toStdString().c_str();
}


void packetSniffer::on_actionExportar_captura_triggered()
{
    // Diálogo para seleccionar el archivo
    QString fileName = QFileDialog::getSaveFileName(this, "Guardar archivo CSV", "", "Archivos CSV (*.csv)");
    if (fileName.isEmpty())
        return;

    // Crear el archivo
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo crear el archivo");
        return;
    }

    QTextStream stream(&file);

    // Escribir los encabezados
    for (int col = 0; col < tableModel->columnCount(); ++col) {
        stream << tableModel->headerData(col, Qt::Horizontal).toString();
        if (col < tableModel->columnCount() - 1)
            stream << ",";
    }
    stream << "\n";

    // Escribir las filas
    for (int row = 0; row < tableModel->rowCount(); ++row) {
        for (int col = 0; col < tableModel->columnCount(); ++col) {
            QModelIndex index = tableModel->index(row, col);
            stream << tableModel->data(index).toString();
            if (col < tableModel->columnCount() - 1)
                stream << ",";
        }
        stream << "\n";
    }

    file.close();

    QMessageBox::information(nullptr, "Éxito", "Archivo CSV exportado con éxito");
}

void packetSniffer::insertData(QString idPack, QString time, QString protocol, QString srcIP, QString destIP,
                               QString ttlPack, QString lenght, QString extraInfo)
{
    QList<QStandardItem *> elemento;
    elemento<< new QStandardItem(idPack)
            << new QStandardItem(time)
            << new QStandardItem(protocol)
            << new QStandardItem(srcIP)
            << new QStandardItem(destIP)
            << new QStandardItem(ttlPack)
            << new QStandardItem(lenght)
            << new QStandardItem(extraInfo);

    tableModel->appendRow(elemento);
    // Desplazar la vista hacia la última fila
    ui->tableView->scrollToBottom();
    Sleep(0.50);
}

void packetSniffer::on_tableView_doubleClicked(const QModelIndex &index)
{
    int fila = index.row();

    ui->rawDataTextEdit->setText(rawDataMap.value(fila,""));
    ui->rawHexDataTextEdit->setText(interpretaRaw(rawDataMap.value(fila,"")));

    QString packetID = tableModel->data(tableModel->index(fila,0)).toString();
    QString time = tableModel->data(tableModel->index(fila, 1)).toString();
    QString protocol = tableModel->data(tableModel->index(fila, 2)).toString();
    QString srcIP = tableModel->data(tableModel->index(fila, 3)).toString();
    QString destIP = tableModel->data(tableModel->index(fila, 4)).toString();
    QString ttl = tableModel->data(tableModel->index(fila, 5)).toString();
    QString length = tableModel->data(tableModel->index(fila, 6)).toString();
    QString extraInfo = tableModel->data(tableModel->index(fila, 7)).toString();


    /*if (rawHexDataTextEdit) {
        rawHexDataTextEdit->clear();
        rawHexDataTextEdit->append("-----------------------------------------------------");
        rawHexDataTextEdit->append("Packet ID: " + packetID);
        rawHexDataTextEdit->append("Protocol: " + protocol);
        rawHexDataTextEdit->append("Source IP: " + srcIP);
        rawHexDataTextEdit->append("Destination IP: " + destIP);
        rawHexDataTextEdit->append("TTL: " + ttl);
        rawHexDataTextEdit->append("Length: " + length);
        rawHexDataTextEdit->append("Extra Info: " + extraInfo);
        rawHexDataTextEdit->append("-----------------------------------------------------");
    }

    if (rawDataTextEdit) {
        rawDataTextEdit->clear();
        rawDataTextEdit->append("-----------------------------------------------------");


        if (!extraInfo.isEmpty() && !extraInfo.contains(QRegularExpression("[^0-9A-Fa-f]"))) {
            qDebug() << "extraInfo is valid hexadecimal data.";
        } else {
            qDebug() << "extraInfo contains invalid characters.";
        }


        QByteArray rawData = QByteArray::fromHex(extraInfo.toUtf8());


        qDebug() << "Raw data size: " << rawData.size();


        QByteArray first64Bytes = rawData.left(64);


        rawDataTextEdit->append("Raw Data (first 64 bytes):");
        QString hexStr = first64Bytes.toHex();

        QString formattedHex = "";
        for (int i = 0; i < hexStr.length(); i += 2) {
            formattedHex.append(hexStr.mid(i, 2) + " ");
        }
        rawDataTextEdit->append(formattedHex);

        qDebug() << "First 64 bytes: " << first64Bytes.toHex();

        rawDataTextEdit->append("-----------------------------------------------------");
    }*/

}

QString packetSniffer::obtenerContenidoRaw(const u_char* data, int length)
{
    QString result;

    for (int i = 0; i < length; i++) {
        result += QString::asprintf("%02X ", data[i]);

        if((i+1)%16 == 0)
        {
            result += "\n";
        }
    }
    return result;
}

QString packetSniffer::interpretaRaw(QString dataRaw)
{
    QString result;
    int protocol;

    result += "  Destination MAC: " + QString::asprintf("%c%c:%c%c:%c%c:%c%c:%c%c:%c%c", dataRaw[0],dataRaw[1],dataRaw[3],dataRaw[4],dataRaw[6],dataRaw[7],
                                                        dataRaw[9],dataRaw[10],dataRaw[12],dataRaw[13],dataRaw[15],dataRaw[16]) + "\n";
    result += "  Source MAC: " + QString::asprintf("%c%c:%c%c:%c%c:%c%c:%c%c:%c%c", dataRaw[18],dataRaw[19],dataRaw[21],dataRaw[22],dataRaw[24],dataRaw[25],
                                                   dataRaw[27],dataRaw[28],dataRaw[30],dataRaw[31],dataRaw[33],dataRaw[34]) + "\n\n";
    return result;
}
