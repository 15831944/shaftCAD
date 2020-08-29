#include "resultdialog.h"
#include "ui_resultdialog.h"
#include "DialogManager.h"
#include "Utils.h"
#include <QMessageBox>



ResultDialog::ResultDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

}

ResultDialog::~ResultDialog()
{
    delete ui;
}

void ResultDialog::on_BtnPre_clicked()
{
//    DialogManager::GetInstance().HideResultDlg();
//    DialogManager::GetInstance().ShowInputParamsDlg();
}

void ResultDialog::show(){

    QDialog::show();

    Shaft * mShaft = DialogManager::GetInstance().GetProject()->GetShaft();

    std::vector<TopArcItem> mVecTop = mShaft->getVecTop();

    double maxTopM = mVecTop[0].getM_wanju(), maxTopN = mVecTop[0].getN_zhouli(),
            minTopM = maxTopM, minTopN = maxTopN;

    for(TopArcItem it : mVecTop){
        if(it.getM_wanju() > maxTopM){
            maxTopM = it.getM_wanju();
        }
        if(it.getM_wanju() < minTopM){
            minTopM = it.getM_wanju();
        }
        if(it.getN_zhouli() > maxTopN){
            maxTopN = it.getN_zhouli();
        }
        if(it.getN_zhouli() < minTopN){
            minTopN = it.getN_zhouli();
        }
    }

    std::vector<BottomItem> mVecBottom = mShaft->getVecBottom();

    double maxBottomM = mVecBottom[0].getM_Wanju(), maxBottomN = mVecBottom[0].getQ_Zhouli(),
            minBottomM = maxBottomM, minBottomN = maxBottomN;
    for(BottomItem it : mVecBottom){
        if(it.getM_Wanju() > maxBottomM){
            maxBottomM = it.getM_Wanju();
        }
        if(it.getM_Wanju() < minBottomM){
            minBottomM = it.getM_Wanju();
        }
        if(it.getQ_Zhouli() > maxBottomN){
            maxBottomN = it.getQ_Zhouli();
        }
        if(it.getQ_Zhouli() < maxBottomN){
            minBottomN = it.getQ_Zhouli();
        }
    }

    std::vector<WallItem> mVecWall = mShaft->getVecWall();

    double maxWallM = mVecWall[0].getM_wanju(), maxWallN = mVecWall[0].getQ_zhouli(),
            minWallM = maxWallM, minWallN = maxWallN;
    for(WallItem it : mVecWall){
        if(it.getM_wanju() > maxWallM){
            maxWallM = it.getM_wanju();
        }
        if(it.getM_wanju() < minWallM){
            minWallM = it.getM_wanju();
        }
        if(it.getQ_zhouli() > maxWallM){
            maxWallN = it.getQ_zhouli();
        }
        if(it.getQ_zhouli() < minWallN){
            minWallN = it.getQ_zhouli();
        }
    }

    ui->mEdtTopMaxM->setText(QString::number(maxTopM));
    ui->mEdtTopMinM->setText(QString::number(minTopM));
    ui->mEdtTopMaxN->setText(QString::number(maxTopN));
    ui->mEdtTopMinN->setText(QString::number(minTopN));

    ui->mEdtWallMaxM->setText(QString::number(maxWallM));
    ui->mEdtWallMinM->setText(QString::number(minWallM));
    ui->mEdtWallMaxN->setText(QString::number(maxWallN));
    ui->mEdtWallMinN->setText(QString::number(minWallN));

    ui->mEdtBottomMaxM->setText(QString::number(maxBottomM));
    ui->mEdtBottomMinM->setText(QString::number(minBottomM));
    ui->mEdtBottomMaxN->setText(QString::number(maxBottomN));
    ui->mEdtBottomMinN->setText(QString::number(minBottomN));

}


void ResultDialog::on_BtnDraw_clicked()
{
    CString filename = CADService::GetAcad2017Path() + _T("ini\\shaft\\bridge.ini");


    if(DialogManager::GetInstance().GetProject()->ProjectSaver(filename) == true) {
        std::cout << "bridge file save successfully!\n";
    }
    else{
        std::cout << "ERROR: Fail to bridge file!\n";
    }


    CADService::WriteAcadRx();
    CADService::LaunchACad();
    QMessageBox::information(NULL, "Message", "绘图成功，AutoCAD已自动启动！");


}

void ResultDialog::on_BtnCancel_clicked()
{
    this->hide();
}
