#include "filtersdialog.h"
#include "ui_filtersdialog.h"

filtersDialog::filtersDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::filtersDialog)
{
    ui->setupUi(this);

    ui->filterWidget->setEnabled(false);
    ui->filterWidget->setStyleSheet("background-color: rgb(30, 40, 35); color: rgb(108,121,47);");
}

filtersDialog::~filtersDialog()
{
    delete ui;
}

void filtersDialog::on_activaCheckBox_clicked()
{
    if(ui->activaCheckBox->isChecked())
    {
        ui->filterWidget->setEnabled(true);
        ui->filterWidget->setStyleSheet("background-color: rgb(20, 35, 25); color: rgb(235, 250, 240);");
    }else{
        ui->filterWidget->setEnabled(false);
        ui->filterWidget->setStyleSheet("background-color: rgb(30, 40, 35); color: rgb(102,111,47);");
    }
}


void filtersDialog::on_cancelButton_clicked()
{
    reject();
}


void filtersDialog::on_okButton_clicked()
{
    if(ui->activaCheckBox->isChecked())
    {
        isFiltro = true;
        if(ui->negarBox->isChecked()){
            filtroStr = "not ";
        }

        if(ui->protocoloRadioButton->isChecked()){
            filtroStr = filtroStr + ui->protocoloLineEdit->text();
        }

        if(ui->destinoRadioButton->isChecked()){
            filtroStr = filtroStr + "dst host " + ui->destinoLineEdit->text();
        }

        if(ui->fuenteRadioButton->isChecked()){
            filtroStr = filtroStr + "src host " + ui->fuenteLineEdit->text();
        }

        if(ui->puertoRadioButton->isChecked()){
            filtroStr = filtroStr + "port " + ui->puertoLineEdit->text();
        }
    }
    else
    {
        isFiltro = false;
        filtroStr = "";
    }

    accept();
}

