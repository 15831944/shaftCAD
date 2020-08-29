#ifndef OUTLOADDIALOG_H
#define OUTLOADDIALOG_H

#include <QDialog>
#include "resultdialog.h"

namespace Ui {
class OutLoadDialog;
}

class OutLoadDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OutLoadDialog(QWidget *parent = nullptr);
    ~OutLoadDialog();

private slots:
    void on_okButton_clicked();

private:
    Ui::OutLoadDialog *ui;
};

#endif // OUTLOADDIALOG_H
