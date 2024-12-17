#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <pcap.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include "packetsniffer.h"
#include "errordialog.h"
#include <QAction>  // Necesario para usar QAction
#include "help.h"  // Incluir la clase de la ventana de ayuda


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();// evento del botón

    void loadWebInterface();// carga la interface de red en el combobox

    void showHelpWindow();  // Declaramos el slot para abrir la ventana de ayuda

    void openManual();



private:
    Ui::MainWindow *ui;

    packetSniffer *ventanaSniffer;
    pcap_if_t * alldevs;


};
#endif // MAINWINDOW_H
