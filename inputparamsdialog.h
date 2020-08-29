#ifndef INPUTPARAMS_H
#define INPUTPARAMS_H

#include <QDialog>

namespace Ui {
class InputParams;
}

class InputParams : public QDialog
{
    Q_OBJECT

public:
    explicit InputParams(QWidget *parent = nullptr);
    ~InputParams();
    void SwitchBottomBoardEnable();
private slots:


    void on_BtnOk_clicked();

    void on_BtnPre_clicked();

    void on_mEdtMaiDepth_editingFinished();

    void on_mBtnCalculateTop_clicked();

    void on_mBtnCalculateBottom_clicked();

    void on_mCalculateWall_clicked();

    void on_BtnCancel_clicked();

private:
    Ui::InputParams *ui;
    bool isCalculatedTop = false;
    bool isCalculatedBottom = false;
    bool isCalculatedWall = false;
};

#endif // INPUTPARAMS_H
