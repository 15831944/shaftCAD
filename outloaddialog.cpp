#include "outloaddialog.h"
#include "ui_outloaddialog.h"

OutLoadDialog::OutLoadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OutLoadDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

}

OutLoadDialog::~OutLoadDialog()
{
    delete ui;
}

void OutLoadDialog::on_okButton_clicked()
{
    ResultDialog *newWin = new ResultDialog;
    newWin->show();
    this->hide();
}
