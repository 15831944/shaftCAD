#include "ui_inputparamsdialog.h"
#include "inputparamsdialog.h"
#include "DialogManager.h"
#include <QMessageBox>

InputParams::InputParams(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputParams)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

    QDoubleValidator *LineDouble = new QDoubleValidator(0, 100000000, 3, nullptr);
    QDoubleValidator *LineSubDouble = new QDoubleValidator(0.81, 1.00, 2, nullptr);
    QDoubleValidator *LineShakeDouble = new QDoubleValidator(1.05, 1.2, 2, nullptr);
    QIntValidator *LineInt = new QIntValidator(0, 10, nullptr);
    QIntValidator *LineBigInt = new QIntValidator(0, 1000, nullptr);

    ui->mEdtConcretePressure->setValidator(LineDouble);
    ui->mEdtRouMin->setValidator(LineDouble);
    ui->mEdtElastic->setValidator(LineDouble);
    ui->mEdtGangjinD->setValidator(LineDouble);
    ui->mEdtMaiDepth->setValidator(LineBigInt);
    ui->mEdtSubNumber->setValidator(LineSubDouble);
    ui->mEdtVecHeight->setValidator(LineDouble);
    ui->mEdtShakeNumber->setValidator(LineShakeDouble);
    ui->mEdtAverageLoad->setValidator(LineDouble);
    ui->mEdtBottomWidth->setValidator(LineDouble);
    ui->mEdtBottomLength->setValidator(LineDouble);
    ui->mEdtStoneWeight->setValidator(LineDouble);
    ui->mEdtTunnelWidth->setValidator(LineDouble);
    ui->mEdtInnerCircleR->setValidator(LineDouble);
    ui->mEdtGroundElastic->setValidator(LineDouble);
    ui->mEdtWallCalLength->setValidator(LineDouble);
    ui->mEdtConcreteWeight->setValidator(LineDouble);
    ui->mEdtGangjinPressure->setValidator(LineDouble);
    ui->mEdtConcretePressure->setValidator(LineDouble);
    ui->mEdtProtectThickness->setValidator(LineDouble);

    ui->mEdtBottomX->setValidator(LineInt);
    ui->mEdtWallX->setValidator(LineInt);

}

void InputParams::SwitchBottomBoardEnable(){

    Shaft *mShaft =  DialogManager::GetInstance().GetProject()->GetShaft();
    if(mShaft != nullptr){

        if(mShaft->GetIsBottomArc() == true){
            ui->mEdtShakeNumber->setEnabled(true);

            ui->mEdtBottomWidth->setEnabled(false);
            ui->mEdtElastic->setEnabled(false);
            ui->mEdtBottomLength->setEnabled(false);
            ui->mEdtProtectThickness->setEnabled(false);
            ui->mEdtAverageLoad->setEnabled(false);
            ui->mEdtBottomX->setEnabled(false);
            ui->mEdtGangjinD->setEnabled(false);
            ui->mEdtGroundElastic->setEnabled(false);

            ui->mEdtBottomThickness->setReadOnly(true);
        }else{
            ui->mEdtShakeNumber->setEnabled(false);

            ui->mEdtBottomWidth->setEnabled(true);
            ui->mEdtElastic->setEnabled(true);
            ui->mEdtBottomLength->setEnabled(true);
            ui->mEdtProtectThickness->setEnabled(true);
            ui->mEdtAverageLoad->setEnabled(true);
            ui->mEdtBottomX->setEnabled(true);
            ui->mEdtGangjinD->setEnabled(true);
            ui->mEdtGroundElastic->setEnabled(true);

            ui->mEdtBottomThickness->setReadOnly(false);
        }
    }
}

InputParams::~InputParams()
{
    delete ui;
}

void UpdateShaftInfo(){

}

void InputParams::on_BtnOk_clicked()
{

    DialogManager::GetInstance().HideInputParamsDlg();
    DialogManager::GetInstance().ShowResultDlg();
}

void InputParams::on_BtnPre_clicked()
{
    DialogManager::GetInstance().HideInputParamsDlg();
    if(DialogManager::GetInstance().GetProject()->GetShaft()->GetIsBottomArc() == true){
        DialogManager::GetInstance().ShowArcTunnelDlg();
    }else{
        DialogManager::GetInstance().ShowLineTunnelDlg();
    }
}

// 当埋深输入完成时判断压力
void InputParams::on_mEdtMaiDepth_editingFinished()
{
    ui->mComboPressure->clear();

    if(ui->mEdtMaiDepth->text().toUInt() < 100){
        ui->mComboPressure->addItem("1.2");
    }
    if(ui->mEdtMaiDepth->text().toInt() >= 100 &&  ui->mEdtMaiDepth->text().toInt() <= 150){

        ui->mComboPressure->addItem("1.2");
        ui->mComboPressure->addItem("1.3");
        ui->mComboPressure->addItem("1.4");
        ui->mComboPressure->addItem("1.5");
    }else if(ui->mEdtMaiDepth->text().toInt() >150 && ui->mEdtMaiDepth->text().toInt() < 200){
        ui->mComboPressure->addItem("1.5");
        ui->mComboPressure->addItem("1.6");
        ui->mComboPressure->addItem("1.7");
        ui->mComboPressure->addItem("1.8");
    }else if(ui->mEdtMaiDepth->text().toInt() >=200 && ui->mEdtMaiDepth->text().toInt() <= 400){
        ui->mComboPressure->addItem(QString::number(0.01 * ui->mEdtMaiDepth->text().toInt()));
    }else if(ui->mEdtMaiDepth->text().toInt() >400 && ui->mEdtMaiDepth->text().toInt() <= 500){
        ui->mComboPressure->addItem(QString::number(0.01 * ui->mEdtMaiDepth->text().toInt()));
        ui->mComboPressure->addItem(QString::number(0.02 * ui->mEdtMaiDepth->text().toInt()));
        ui->mComboPressure->addItem(QString::number(0.03 * ui->mEdtMaiDepth->text().toInt()));
        ui->mComboPressure->addItem(QString::number(0.04 * ui->mEdtMaiDepth->text().toInt()));
        ui->mComboPressure->addItem(QString::number(0.05 * ui->mEdtMaiDepth->text().toInt()));
        ui->mComboPressure->addItem(QString::number(0.06 * ui->mEdtMaiDepth->text().toInt()));
        ui->mComboPressure->addItem(QString::number(0.07 * ui->mEdtMaiDepth->text().toInt()));
        ui->mComboPressure->addItem(QString::number(0.08 * ui->mEdtMaiDepth->text().toInt()));
        ui->mComboPressure->addItem(QString::number(0.09 * ui->mEdtMaiDepth->text().toInt()));
        ui->mComboPressure->addItem(QString::number(0.10 * ui->mEdtMaiDepth->text().toInt()));
        ui->mComboPressure->addItem(QString::number(0.11 * ui->mEdtMaiDepth->text().toInt()));
        ui->mComboPressure->addItem(QString::number(0.12 * ui->mEdtMaiDepth->text().toInt()));
    }

}

void InputParams::on_mBtnCalculateTop_clicked()
{
    Shaft * mShaft = DialogManager::GetInstance().GetProject()->GetShaft();
    mShaft->SetFc(ui->mEdtConcretePressure->text().toDouble());
    mShaft->SetRoumin(ui->mEdtRouMin->text().toDouble());
    mShaft->SetFy(ui->mEdtGangjinPressure->text().toDouble());
    mShaft->SetH(ui->mEdtMaiDepth->text().toDouble());
    mShaft->SetRn(ui->mCalculateR->text().toDouble());
    mShaft->SetPk1(ui->mComboPressure->currentText().toDouble());
    mShaft->SetKz(ui->mEdtSubNumber->text().toDouble());

    isCalculatedTop = true;

    QMessageBox::information(NULL, "Message", "顶板厚度计算成功！");

    ui->mEdtResultTopThickness->setText(QString::number(mShaft->GetTopThickness()));

}

void InputParams::on_mBtnCalculateBottom_clicked()
{
    Shaft * mShaft = DialogManager::GetInstance().GetProject()->GetShaft();
    if(mShaft->GetIsBottomArc() == true){
        mShaft->SetLambda(ui->mEdtShakeNumber->text().toDouble());
    }else{
        mShaft->setBottomWidth(ui->mEdtBottomWidth->text().toDouble());
        mShaft->setElastic(ui->mEdtElastic->text().toDouble());
        mShaft->setBottomLength(ui->mEdtBottomLength->text().toDouble());
        mShaft->setQ_AverageLoad(ui->mEdtAverageLoad->text().toDouble());
        mShaft->setBottomKeyX(ui->mEdtBottomX->text().toUInt());
        mShaft->setProtectThickness(ui->mEdtProtectThickness->text().toDouble());
        mShaft->setGangjinD(ui->mEdtGangjinD->text().toDouble());
        mShaft->setK_elastic_coefficient(ui->mEdtGroundElastic->text().toDouble());
        mShaft->setBottomThickness(ui->mEdtBottomThickness->text().toDouble());
    }

    if(isCalculatedTop == true){

        QMessageBox::information(NULL, "Message", "底板厚度计算成功！");

        ui->mEdtBottomThickness->setText(QString::number(mShaft->GetBottomThickness()));
        isCalculatedBottom = true;
    }else{
        QMessageBox::warning(this, "警告", "请先计算顶板厚度！");

    }

}

void InputParams::on_mCalculateWall_clicked()
{
    Shaft * mShaft = DialogManager::GetInstance().GetProject()->GetShaft();
    mShaft->setTopKeyX(ui->mEdtTopX->text().toUInt());
    mShaft->setWallKeyX(ui->mEdtWallX->text().toUInt());
    mShaft->setF0_InnerCircleHeight(ui->mEdtVecHeight->text().toDouble());
    mShaft->setL0_InnerCircleWidth(ui->mEdtInnerCircleR->text().toDouble());
    mShaft->setH1_wallHeight(ui->mEdtWallCalLength->text().toDouble());
    mShaft->setStoneLevel(ui->mComboStoneLevel->currentIndex()+1);
    mShaft->setB_TunnelWidth(ui->mEdtTunnelWidth->text().toDouble());
    mShaft->setGamma0_StoneWeight(ui->mEdtStoneWeight->text().toDouble());
    mShaft->setGamma_concreteWeight(ui->mEdtConcreteWeight->text().toDouble());
    mShaft->setWallThickness(ui->mEdtWallThickness->text().toDouble());

    if(isCalculatedTop == true && isCalculatedBottom == true){

        QMessageBox::information(NULL, "Message", "直墙厚度计算成功！");

        ui->mEdtWallThickness->setText( QString::number(mShaft->GetWallThickness()));
        isCalculatedWall = true;
    }else if(isCalculatedTop == false){
        QMessageBox::warning(this, "警告", "请先计算顶板厚度！");

    }else if(isCalculatedWall == false){
        QMessageBox::warning(this, "警告", "请先计算底板厚度！");

    }
}

void InputParams::on_BtnCancel_clicked()
{
    this->hide();
}
