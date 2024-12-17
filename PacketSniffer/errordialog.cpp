#include "errordialog.h"
#include "ui_errordialog.h"

errorDialog::errorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::errorDialog)
{
    ui->setupUi(this);
}

errorDialog::~errorDialog()
{
    delete ui;
}

void errorDialog::on_buttonBox_accepted()
{
    QWidget *padre = this->parentWidget();
    if(padre)
    {
        this->setParent(nullptr);
        delete padre;
    }
    this->accept();
}

void errorDialog::setDialog(std::string errorMessage)
{
    ui->errorLabel->setText(QString::fromStdString(errorMessage));
}
