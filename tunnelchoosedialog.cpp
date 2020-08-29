#include "tunnelchoosedialog.h"
#include "ui_tunnelchoosedialog.h"

TunnelChooseDialog::TunnelChooseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TunnelChooseDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

}

TunnelChooseDialog::~TunnelChooseDialog()
{
    delete ui;
}

void TunnelChooseDialog::on_okBtn_clicked()
{

}
