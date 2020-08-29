#ifndef TUNNELCHOOSEDIALOG_H
#define TUNNELCHOOSEDIALOG_H

#include <QDialog>
#include "inputparamsdialog.h"
namespace Ui {
class TunnelChooseDialog;
}

class TunnelChooseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TunnelChooseDialog(QWidget *parent = nullptr);
    ~TunnelChooseDialog();

private slots:
    void on_okBtn_clicked();

private:
    Ui::TunnelChooseDialog *ui;
};

#endif // TUNNELCHOOSEDIALOG_H
