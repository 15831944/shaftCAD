#include "projectdialog.h"
#include "ui_projectdialog.h"
#include "DialogManager.h"
#include <QString>
#include <iostream>
#include <string>

ProjectDialog::ProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);

}

ProjectDialog::~ProjectDialog()
{
    delete ui;
}

void ProjectDialog::on_BtnOk_clicked()
{
    DialogManager::GetInstance().NewProject();
    InitProjectInfo();
    DialogManager::GetInstance().ShowArcTunnelChooseDlg();
    DialogManager::GetInstance().HideProjectDialog();
}

void ProjectDialog::InitProjectInfo(){
    DialogManager::GetInstance().GetProject()->SetTitle(ui->edt_papertitle->text());
    DialogManager::GetInstance().GetProject()->SetDescription(ui->edt_paper_description->text());
    DialogManager::GetInstance().GetProject()->SetScaleNumber(ui->edt_scale_number->text());
    DialogManager::GetInstance().GetProject()->SetPaperNumber(ui->edt_paper_number->text());
    DialogManager::GetInstance().GetProject()->SetPaperSize(ui->combo_paper_size->currentText());
    DialogManager::GetInstance().GetProject()->SetDesigner(ui->edt_designer->text());
    DialogManager::GetInstance().GetProject()->SetDesignApart(ui->edt_design_apart->text());
    DialogManager::GetInstance().GetProject()->SetChecker(ui->edt_checker->text());
    DialogManager::GetInstance().GetProject()->SetDate(ui->dateEdit_date->text());
    DialogManager::GetInstance().GetProject()->SetCheckDate(ui->dateEdit_check_date->text());


    std::cout << "Project title: " << (char*)DialogManager::GetInstance().GetProject()->GetTitle().c_str() << std::endl;
}

void ProjectDialog::UpdateProjectUi(){

}

void ProjectDialog::on_BtnCancel_clicked()
{
    this->hide();
}
