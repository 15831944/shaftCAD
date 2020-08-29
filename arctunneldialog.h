#ifndef PARAMDIALOG_H
#define PARAMDIALOG_H

#include <QDialog>
#include "outloaddialog.h"

namespace Ui {
class ArcTunnelDialog;
}

class ArcTunnelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ArcTunnelDialog(QWidget *parent = nullptr);
    ~ArcTunnelDialog();

private slots:
    void on_okButton_clicked();

    void on_preButton_clicked();


    void on_cancleButton_clicked();

private:
    Ui::ArcTunnelDialog *ui;

    void UpdateTunnelBasicInfo();
};

#endif // PARAMDIALOG_H
