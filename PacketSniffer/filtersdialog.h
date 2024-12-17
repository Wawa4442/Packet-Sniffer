#ifndef FILTERSDIALOG_H
#define FILTERSDIALOG_H

#include <QDialog>

namespace Ui {
class filtersDialog;
}

class filtersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit filtersDialog(QWidget *parent = nullptr);
    ~filtersDialog();

    bool isFiltro;
    QString filtroStr;

private slots:
    void on_activaCheckBox_clicked();

    void on_cancelButton_clicked();

    void on_okButton_clicked();

private:
    Ui::filtersDialog *ui;
};

#endif // FILTERSDIALOG_H
