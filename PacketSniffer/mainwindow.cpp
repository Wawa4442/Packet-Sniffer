#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "help.h"  // Incluir la clase de ayuda
#include <QAction>
#include <QMenuBar>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadWebInterface();

    // Crear la acción de ayuda
    QAction *helpAction = new QAction("Ayuda", this);

    // Conectar la acción con el slot para abrir la ventana de ayuda
    connect(helpAction, &QAction::triggered, this, &MainWindow::showHelpWindow);

    // Crear un menú y agregar la acción de ayuda
    QMenu *helpMenu = menuBar()->addMenu("Ayuda");
    helpMenu->addAction(helpAction);

    // Crear una acción en el QMenu
    QAction *manualAction = new QAction("Manual", this);

    // Agregar la acción al menú
    ui->menuManual->addAction(manualAction);

    // Conectar la acción con el slot para abrir el manual
    connect(manualAction, &QAction::triggered, this, &MainWindow::openManual);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{//inicia la otra ventana y le manda la inteface de red seleccionada
    const char *currentText = ui->comboBox->currentText().toStdString().c_str();

    if(std::strcmp("[ SELECCIONA UNA INTERFAZ DE RED ]",currentText))
    {
        pcap_if_t* search;
        for (search = alldevs; search != NULL; search = search->next) {
            if (!std::strcmp(search->description,currentText))
            {
                QString selectedDevice = search->name;
                ventanaSniffer = new packetSniffer();
                //ventanaSniffer->show();
                ventanaSniffer->selected_Interface(selectedDevice);
                this->hide();
            }
        }
        pcap_freealldevs(alldevs);
    }
    else
    {
        errorDialog ventanaError;
        ventanaError.setDialog("Sleccione una opción válida");
    }
}

void MainWindow::loadWebInterface()
{
    ui->comboBox->addItem("[ SELECCIONA UNA INTERFAZ DE RED ]");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_if_t* device;
    //int device_number, i = 0;

    // Encuentra todas las interfaces de red disponibles
    if (pcap_findalldevs(&alldevs, error_buffer) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", error_buffer);
    }

    // Lista todas las interfaces disponibles
    printf("Available devices:\n");
    for (device = alldevs; device != NULL; device = device->next) {
        if (device->description)
            ui->comboBox->addItem(device->description);
    }
}

void MainWindow::showHelpWindow()
{
    help *helpWindow = new help(this);  // Crear la ventana de ayuda
    helpWindow->exec();  // Mostrar la ventana de forma modal
}

// Método que abrirá el manual en el navegador
void MainWindow::openManual()
{
    // URL del manual
    QUrl manualUrl("https://aulavirtual.uaa.mx");

    // Verificar si la URL es válida antes de abrirla
    if (manualUrl.isValid()) {
        QDesktopServices::openUrl(manualUrl); // Abre el enlace en el navegador predeterminado
    } else {
        // Si la URL no es válida, mostrar un mensaje de error
        QMessageBox::warning(this, "Error", "La URL del manual no es válida.");
    }
}

