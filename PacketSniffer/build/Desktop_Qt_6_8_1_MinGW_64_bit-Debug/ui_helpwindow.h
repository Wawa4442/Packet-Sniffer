/********************************************************************************
** Form generated from reading UI file 'helpwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPWINDOW_H
#define UI_HELPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_helpWindow
{
public:

    void setupUi(QDialog *helpWindow)
    {
        if (helpWindow->objectName().isEmpty())
            helpWindow->setObjectName("helpWindow");
        helpWindow->resize(1023, 869);

        retranslateUi(helpWindow);

        QMetaObject::connectSlotsByName(helpWindow);
    } // setupUi

    void retranslateUi(QDialog *helpWindow)
    {
        helpWindow->setWindowTitle(QCoreApplication::translate("helpWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class helpWindow: public Ui_helpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPWINDOW_H
