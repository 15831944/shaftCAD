#ifndef LINETUNNELDIALOG_H
#define LINETUNNELDIALOG_H

#include <QDialog>

namespace Ui {
class LineTunnelDialog;
}

class LineTunnelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LineTunnelDialog(QWidget *parent = nullptr);
    ~LineTunnelDialog();


private slots:

    void on_okButton_clicked();
    
    void on_preButton_clicked();

    void on_cancleButton_clicked();

private:
    Ui::LineTunnelDialog *ui;
    void UpdateTunnelBasicInfo();
};

#endif // LINETUNNELDIALOG_H
