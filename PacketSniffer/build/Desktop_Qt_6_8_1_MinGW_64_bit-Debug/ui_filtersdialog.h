/********************************************************************************
** Form generated from reading UI file 'filtersdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERSDIALOG_H
#define UI_FILTERSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_filtersDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *activaCheckBox;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_9;
    QWidget *filterWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *protocoloRadioButton;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *protocoloLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *fuenteRadioButton;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *fuenteLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *destinoRadioButton;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *destinoLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QRadioButton *puertoRadioButton;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *puertoLineEdit;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *negarBox;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *filtersDialog)
    {
        if (filtersDialog->objectName().isEmpty())
            filtersDialog->setObjectName("filtersDialog");
        filtersDialog->resize(572, 376);
        filtersDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 35, 25);\n"
"color: rgb(235, 250, 240);"));
        verticalLayout = new QVBoxLayout(filtersDialog);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(filtersDialog);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        activaCheckBox = new QCheckBox(filtersDialog);
        activaCheckBox->setObjectName("activaCheckBox");
        activaCheckBox->setChecked(false);

        horizontalLayout_2->addWidget(activaCheckBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);

        filterWidget = new QWidget(filtersDialog);
        filterWidget->setObjectName("filterWidget");
        filterWidget->setEnabled(true);
        filterWidget->setMinimumSize(QSize(500, 250));
        verticalLayout_2 = new QVBoxLayout(filterWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        protocoloRadioButton = new QRadioButton(filterWidget);
        protocoloRadioButton->setObjectName("protocoloRadioButton");

        horizontalLayout_3->addWidget(protocoloRadioButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        protocoloLineEdit = new QLineEdit(filterWidget);
        protocoloLineEdit->setObjectName("protocoloLineEdit");

        horizontalLayout_3->addWidget(protocoloLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        fuenteRadioButton = new QRadioButton(filterWidget);
        fuenteRadioButton->setObjectName("fuenteRadioButton");

        horizontalLayout_4->addWidget(fuenteRadioButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        fuenteLineEdit = new QLineEdit(filterWidget);
        fuenteLineEdit->setObjectName("fuenteLineEdit");

        horizontalLayout_4->addWidget(fuenteLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        destinoRadioButton = new QRadioButton(filterWidget);
        destinoRadioButton->setObjectName("destinoRadioButton");

        horizontalLayout_6->addWidget(destinoRadioButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        destinoLineEdit = new QLineEdit(filterWidget);
        destinoLineEdit->setObjectName("destinoLineEdit");

        horizontalLayout_6->addWidget(destinoLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        puertoRadioButton = new QRadioButton(filterWidget);
        puertoRadioButton->setObjectName("puertoRadioButton");

        horizontalLayout_5->addWidget(puertoRadioButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        puertoLineEdit = new QLineEdit(filterWidget);
        puertoLineEdit->setObjectName("puertoLineEdit");

        horizontalLayout_5->addWidget(puertoLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        negarBox = new QCheckBox(filterWidget);
        negarBox->setObjectName("negarBox");

        horizontalLayout_9->addWidget(negarBox);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_11);


        verticalLayout_2->addLayout(horizontalLayout_9);


        horizontalLayout_8->addWidget(filterWidget);

        horizontalSpacer_10 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);

        okButton = new QPushButton(filtersDialog);
        okButton->setObjectName("okButton");

        horizontalLayout_7->addWidget(okButton);

        cancelButton = new QPushButton(filtersDialog);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout_7->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_7);


        retranslateUi(filtersDialog);

        QMetaObject::connectSlotsByName(filtersDialog);
    } // setupUi

    void retranslateUi(QDialog *filtersDialog)
    {
        filtersDialog->setWindowTitle(QCoreApplication::translate("filtersDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("filtersDialog", "Selecci\303\263n de Filtros", nullptr));
        activaCheckBox->setText(QCoreApplication::translate("filtersDialog", "Activar de Filtros", nullptr));
        protocoloRadioButton->setText(QCoreApplication::translate("filtersDialog", "Protocolo", nullptr));
        fuenteRadioButton->setText(QCoreApplication::translate("filtersDialog", "IP Fuente", nullptr));
        destinoRadioButton->setText(QCoreApplication::translate("filtersDialog", "IP Destino", nullptr));
        puertoRadioButton->setText(QCoreApplication::translate("filtersDialog", "Puerto", nullptr));
        negarBox->setText(QCoreApplication::translate("filtersDialog", "Negar Filtro", nullptr));
        okButton->setText(QCoreApplication::translate("filtersDialog", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("filtersDialog", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class filtersDialog: public Ui_filtersDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERSDIALOG_H
