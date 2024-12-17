/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_help
{
public:
    QFrame *frame;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;

    void setupUi(QDialog *help)
    {
        if (help->objectName().isEmpty())
            help->setObjectName("help");
        help->resize(903, 779);
        frame = new QFrame(help);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(-1, -1, 901, 771));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        textEdit = new QTextEdit(frame);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(90, 100, 731, 631));
        textEdit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-color: rgb(228, 255, 225);\n"
"font: 16pt \"Tw Cen MT\";"));
        textEdit_2 = new QTextEdit(frame);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(130, 20, 641, 61));
        textEdit_2->setStyleSheet(QString::fromUtf8("font: 9pt \"Stencil\";\n"
"color: rgb(170, 0, 0);"));

        retranslateUi(help);

        QMetaObject::connectSlotsByName(help);
    } // setupUi

    void retranslateUi(QDialog *help)
    {
        help->setWindowTitle(QCoreApplication::translate("help", "Dialog", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Stencil'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:20pt; font-weight:700;\">BIENVENIDO A LA SECCION DE AYUDA</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI'; font-size:20pt; font-weight:700;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class help: public Ui_help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
