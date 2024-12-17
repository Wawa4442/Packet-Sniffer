/********************************************************************************
** Form generated from reading UI file 'packetsniffer.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACKETSNIFFER_H
#define UI_PACKETSNIFFER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_packetSniffer
{
public:
    QAction *actionFiltros;
    QAction *actionExportar_captura;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *rawHexDataTextEdit;
    QTextEdit *rawDataTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *startButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *stopButton;
    QSpacerItem *horizontalSpacer_4;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuCaptura;

    void setupUi(QMainWindow *packetSniffer)
    {
        if (packetSniffer->objectName().isEmpty())
            packetSniffer->setObjectName("packetSniffer");
        packetSniffer->resize(860, 600);
        packetSniffer->setMinimumSize(QSize(860, 400));
        packetSniffer->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 62, 44);"));
        actionFiltros = new QAction(packetSniffer);
        actionFiltros->setObjectName("actionFiltros");
        actionExportar_captura = new QAction(packetSniffer);
        actionExportar_captura->setObjectName("actionExportar_captura");
        centralwidget = new QWidget(packetSniffer);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(116, 150, 137);"));

        horizontalLayout->addWidget(tableView);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(0, 200));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        rawHexDataTextEdit = new QTextEdit(frame);
        rawHexDataTextEdit->setObjectName("rawHexDataTextEdit");
        rawHexDataTextEdit->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";"));

        horizontalLayout_3->addWidget(rawHexDataTextEdit);

        rawDataTextEdit = new QTextEdit(frame);
        rawDataTextEdit->setObjectName("rawDataTextEdit");
        rawDataTextEdit->setStyleSheet(QString::fromUtf8("font: 10pt \"Consolas\";"));

        horizontalLayout_3->addWidget(rawDataTextEdit);


        verticalLayout_2->addWidget(frame);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setStyleSheet(QString::fromUtf8("background-color: rgb(47, 121, 86);\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(startButton);

        horizontalSpacer_5 = new QSpacerItem(50, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName("stopButton");
        stopButton->setEnabled(true);
        stopButton->setStyleSheet(QString::fromUtf8("background-color: rgb(47, 121, 86);\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(stopButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        packetSniffer->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(packetSniffer);
        statusbar->setObjectName("statusbar");
        packetSniffer->setStatusBar(statusbar);
        menuBar = new QMenuBar(packetSniffer);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 860, 25));
        menuCaptura = new QMenu(menuBar);
        menuCaptura->setObjectName("menuCaptura");
        packetSniffer->setMenuBar(menuBar);

        menuBar->addAction(menuCaptura->menuAction());
        menuCaptura->addAction(actionFiltros);
        menuCaptura->addAction(actionExportar_captura);

        retranslateUi(packetSniffer);

        QMetaObject::connectSlotsByName(packetSniffer);
    } // setupUi

    void retranslateUi(QMainWindow *packetSniffer)
    {
        packetSniffer->setWindowTitle(QCoreApplication::translate("packetSniffer", "WireFish", nullptr));
        actionFiltros->setText(QCoreApplication::translate("packetSniffer", "Filtros", nullptr));
        actionExportar_captura->setText(QCoreApplication::translate("packetSniffer", "Exportar captura", nullptr));
        startButton->setText(QCoreApplication::translate("packetSniffer", "Start", nullptr));
        stopButton->setText(QCoreApplication::translate("packetSniffer", "Stop", nullptr));
        menuCaptura->setTitle(QCoreApplication::translate("packetSniffer", "Captura", nullptr));
    } // retranslateUi

};

namespace Ui {
    class packetSniffer: public Ui_packetSniffer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACKETSNIFFER_H
