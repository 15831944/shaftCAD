#include "arctunneldialog.h"
#include "ui_arctunneldialog.h"
#include "DialogManager.h"
#include <QMessageBox>

ArcTunnelDialog::ArcTunnelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArcTunnelDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
}

ArcTunnelDialog::~ArcTunnelDialog()
{
    delete ui;
}

void ArcTunnelDialog::UpdateTunnelBasicInfo(){
    Shaft * mShaft =  DialogManager::GetInstance().GetProject()->GetShaft();
    mShaft->SetBottomArcR(ui->mEdtBottomArcR->text().toDouble());
    mShaft->SetHalfCircleR(ui->mEdtHalfCircleR->text().toDouble());
    mShaft->SetWallHeight(ui->mEdtWallHeight->text().toDouble());
}

void ArcTunnelDialog::on_okButton_clicked()
{

    if(ui->mEdtBottomArcR->text().isEmpty() ||
            ui->mEdtWallHeight->text().isEmpty()||
            ui->mEdtHalfCircleR->text().isEmpty()){
        QMessageBox::warning(this, "警告", "井壁参数值不能为空！");

    }else{
        UpdateTunnelBasicInfo();
        DialogManager::GetInstance().HideArcTunnelDlg();
        DialogManager::GetInstance().ShowInputParamsDlg();
    }


}

void ArcTunnelDialog::on_preButton_clicked()
{
    DialogManager::GetInstance().HideArcTunnelDlg();
    DialogManager::GetInstance().ShowArcTunnelChooseDlg();
}

void ArcTunnelDialog::on_cancleButton_clicked()
{
    this->hide();
}
