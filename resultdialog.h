#ifndef RESULTDIALOG_H
#define RESULTDIALOG_H

#include <QDialog>


namespace Ui {
class ResultDialog;
}

class ResultDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResultDialog(QWidget *parent = nullptr);
    ~ResultDialog();

public slots:
    void show();
private slots:
    void on_BtnPre_clicked();

    void on_BtnDraw_clicked();

    void on_BtnCancel_clicked();

private:
    Ui::ResultDialog *ui;
};

#endif // RESULTDIALOG_H
