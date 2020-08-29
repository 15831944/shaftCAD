#include "linetunneldialog.h"
#include "ui_linetunneldialog.h"
#include "DialogManager.h"
#include <QMessageBox>

LineTunnelDialog::LineTunnelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LineTunnelDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

}

LineTunnelDialog::~LineTunnelDialog()
{
    delete ui;
}

void LineTunnelDialog::UpdateTunnelBasicInfo(){
    Shaft * mShaft =  DialogManager::GetInstance().GetProject()->GetShaft();
    mShaft->SetHalfCircleR(ui->mEdtCircleR->text().toDouble());
    mShaft->SetWallHeight(ui->mEdtHeight->text().toDouble());
}

void LineTunnelDialog::on_okButton_clicked()
{
    if(ui->mEdtHeight->text().isEmpty() || ui->mEdtCircleR->text().isEmpty()){
        QMessageBox::warning(this, "警告", "井壁参数值不能为空！");
    }else{
        UpdateTunnelBasicInfo();
        DialogManager::GetInstance().HideLineTunnelDlg();
        DialogManager::GetInstance().ShowInputParamsDlg();
    }
}

void LineTunnelDialog::on_preButton_clicked()
{
    DialogManager::GetInstance().HideLineTunnelDlg();
    DialogManager::GetInstance().ShowArcTunnelChooseDlg();
}

void LineTunnelDialog::on_cancleButton_clicked()
{
    this->hide();
}
