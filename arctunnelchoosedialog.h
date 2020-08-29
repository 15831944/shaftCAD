#ifndef ARCTUNNELCHOOSEDIALOG_H
#define ARCTUNNELCHOOSEDIALOG_H

#include <QDialog>
#include <QButtonGroup>

namespace Ui {
class ArcTunnelChooseDialog;
}

class ArcTunnelChooseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ArcTunnelChooseDialog(QWidget *parent = nullptr);
    ~ArcTunnelChooseDialog();

private slots:
    void on_okBtn_clicked();

    
    void on_preBtn_clicked();

    void on_cancleBtn_clicked();

private:
    Ui::ArcTunnelChooseDialog *ui;

    QButtonGroup *TunnelGroup;
};

#endif // ARCTUNNELCHOOSEDIALOG_H
