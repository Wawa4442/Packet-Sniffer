#ifndef PACKETSNIFFER_H
#define PACKETSNIFFER_H

#include <QStandardItemModel>
#include <QTableView>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QMainWindow>
#include <QThread>
#include <pcap.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include "errordialog.h"
#include "filtersdialog.h"
#include <QTextEdit>

#pragma comment(lib, "ws2_32.lib") // Vincular la biblioteca de sockets de Windows
#define TH_FIN  0x01
#define TH_SYN  0x02
#define TH_RST  0x04
#define TH_PUSH 0x08
#define TH_ACK  0x10
#define TH_URG  0x20
#define TH_ECE  0x40
#define TH_CWR  0x80

// Estructura TCP (simplificada)
struct tcphdr {
    uint16_t source;     // Puerto de origen
    uint16_t dest;       // Puerto de destino
    uint32_t seq;        // Número de secuencia
    uint32_t ack_seq;    // Número de acuse de recibo
    uint8_t th_res1 : 4; // Bits reservados
    uint8_t th_off : 4;  // Longitud del encabezado
    uint8_t th_flags;    // Flags TCP
    uint16_t window;     // Tamaño de ventana
    uint16_t check;      // Checksum
    uint16_t urg_ptr;    // Puntero urgente
};

// Estructura UDP (simplificada)
struct udphdr {
    uint16_t source;    // Puerto de origen
    uint16_t dest;      // Puerto de destino
    uint16_t len;       // Longitud
    uint16_t check;     // Checksum
};

// Definir manualmente la estructura IP en Windows
struct iphdr {
    unsigned char ihl : 4;  // Longitud del encabezado
    unsigned char version : 4;  // Versión
    uint8_t tos;  // Tipo de servicio
    uint16_t tot_len;  // Longitud total
    uint16_t id;  // ID del paquete
    uint16_t frag_off;  // Offset de fragmento
    uint8_t ttl;  // Tiempo de vida
    uint8_t protocol;  // Protocolo
    uint16_t check;  // Checksum
    struct in_addr saddr;  // Dirección IP de origen
    struct in_addr daddr;  // Dirección IP de destino
};

// Definir encabezado ICMP manualmente
struct icmp_hdr {
    uint8_t type;    // Tipo de mensaje ICMP
    uint8_t code;    // Código del mensaje
    uint16_t checksum;
    uint16_t id;
    uint16_t sequence;
};

namespace Ui {
class packetSniffer;
}

class captura : public QThread{
    Q_OBJECT

public :
    explicit captura(QObject *parrent = nullptr, pcap_t *capdev=nullptr);
    static void callback_function(u_char *user, const struct pcap_pkthdr *pkthdr, const u_char *packet);


signals:
    void capturaPacket(int packet_id, int packet_ttl, int packet_protocol,
                       const QString& srcIP, const QString& dstIP,
                       const u_char* packetd_ptr, const QString& lengthStr, struct iphdr* ip_hdr,
                       u_char* user, const u_char* packet, captura* self);

protected:
    void run() override;

private:
    pcap_t *capdev;

};

class packetSniffer : public QMainWindow
{
    Q_OBJECT

public:

    explicit packetSniffer(QWidget *parent = nullptr);
    ~packetSniffer();

    void start();//inicia la ventana
    void selected_Interface(const QString &selectedInterface);
    // Función para agregar un paquete
    void agregarPaquete(int packet_id, int packet_ttl, int packet_protocol,
                        const QString& packet_srcip, const QString& packet_dstip,
                        const u_char* packetd_ptr, const QString& lengthStr, struct iphdr* ip_hdr,
                        u_char* user, const u_char* packet, captura* self);

    void insertData(QString idPack, QString time, QString protocol, QString srcIP, QString destIP,
                    QString ttlPack, QString lenght, QString extraInfo);

    QString obtenerContenidoRaw(const u_char* data, int length);
    QString interpretaRaw(QString dataRaw);

private slots:
    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_actionFiltros_triggered();

    void on_actionExportar_captura_triggered();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
/*
    Ui::packetSniffer *ui;
    pcap_if_t* globalDevice;*/
    Ui::packetSniffer *ui;
    captura *captura1;
    void HiloCaptura(pcap_t* capdev);
    pcap_if_t *dispositoElegido;
    pcap_t* capdev;

    QTableView *tableView;
    QStandardItemModel *tableModel;

    QTextEdit *rawDataTextEdit;
    QTextEdit *rawHexDataTextEdit;


    bool isFiltro;
    QString filtroStr;
};

#endif // PACKETSNIFFER_H
