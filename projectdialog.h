#ifndef PROJECTDIALOG_H
#define PROJECTDIALOG_H

#include <QDialog>

namespace Ui {
class ProjectDialog;
}

class ProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectDialog(QWidget *parent = nullptr);
    ~ProjectDialog();

private slots:
    void on_BtnOk_clicked();

    void on_BtnCancel_clicked();

private:
    Ui::ProjectDialog *ui;
    // 将 Ui 界面里的信息初始化到程序中
    void InitProjectInfo();
    // 将程序中的 Project 值更新到界面里
    void UpdateProjectUi();
};

#endif // PROJECTDIALOG_H
