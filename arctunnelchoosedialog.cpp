#include "arctunnelchoosedialog.h"
#include "ui_arctunnelchoosedialog.h"
#include "projectdialog.h"
#include "DialogManager.h"
#include <QMessageBox>


ArcTunnelChooseDialog::ArcTunnelChooseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArcTunnelChooseDialog)
{
    ui->setupUi(this);
      setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
      TunnelGroup = new QButtonGroup(this);
      TunnelGroup->addButton(ui->radio_bottom_arc, 0);
      TunnelGroup->addButton(ui->radio_circle_arc, 0);
}

ArcTunnelChooseDialog::~ArcTunnelChooseDialog()
{
    delete ui;
}

void ArcTunnelChooseDialog::on_okBtn_clicked()
{
    if(ui->radio_bottom_arc->isChecked()){

        if(DialogManager::GetInstance().GetProject()->GetShaft() == nullptr){
            DialogManager::GetInstance().GetProject()->NewShaft();
        }

        DialogManager::GetInstance().GetProject()->GetShaft()->SetIsBottomArc(true);


        DialogManager::GetInstance().HideArcTunnelChooseDlg();
        DialogManager::GetInstance().ShowArcTunnelDlg();
    }
    else if(ui->radio_circle_arc->isChecked()){

        if(DialogManager::GetInstance().GetProject()->GetShaft() == nullptr){
            DialogManager::GetInstance().GetProject()->NewShaft();
        }

        DialogManager::GetInstance().GetProject()->GetShaft()->SetIsBottomArc(false);

        DialogManager::GetInstance().HideArcTunnelChooseDlg();
        DialogManager::GetInstance().ShowLineTunnelDlg();
    }
    else{
      QMessageBox::information(NULL, "警告", "请选择一种井壁");
    }
}

void ArcTunnelChooseDialog::on_preBtn_clicked()
{
    DialogManager::GetInstance().HideArcTunnelChooseDlg();
    DialogManager::GetInstance().ShowProjectDialog();
}

void ArcTunnelChooseDialog::on_cancleBtn_clicked()
{
    this->hide();
}
