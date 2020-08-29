#ifndef DIALOGMANAGER_H
#define DIALOGMANAGER_H
#include "projectdialog.h"
#include "arctunnelchoosedialog.h"
#include "arctunneldialog.h"
#include "linetunneldialog.h"
#include "inputparamsdialog.h"
#include "resultdialog.h"
#include "project.h"




class DialogManager{
    
public:
    ~DialogManager(){
        delete mProjectDlg;
        delete mArcTunnelChooseDlg;
        delete mArcTunnelDlg;
        delete mLineTunnelDlg;
        delete mInputParamsDlg;
        delete mResultDlg;
    };
    DialogManager(const DialogManager&)=delete ;
    DialogManager& operator=(const DialogManager&) = delete;
    static DialogManager& GetInstance(){
        static DialogManager instance;
        return instance;
    }
    void ShowProjectDialog(){
        mProjectDlg->show();
    };
    void HideProjectDialog(){
        mProjectDlg->hide();
    };
    void ShowArcTunnelChooseDlg(){
        mArcTunnelChooseDlg->show();
    };
    void HideArcTunnelChooseDlg(){
        mArcTunnelChooseDlg->hide();
    };
    void ShowArcTunnelDlg(){
        mArcTunnelDlg->show();
    };
    void HideArcTunnelDlg(){
        mArcTunnelDlg->hide();
    };
    void ShowLineTunnelDlg(){
        mLineTunnelDlg->show();
    };
    void HideLineTunnelDlg(){
        mLineTunnelDlg->hide();
    };
    void ShowInputParamsDlg(){
        mInputParamsDlg->show();
        mInputParamsDlg->SwitchBottomBoardEnable();
    };
    void HideInputParamsDlg(){
        mInputParamsDlg->hide();
    };
    void ShowResultDlg(){
        mResultDlg->show();
    };
    void HideResultDlg(){
        mResultDlg->hide();
    };
    void NewProject(){
        mProject = new Project();
    };
    Project* GetProject(){
        return mProject;
    };
    void SetProject(Project &project){
        mProject = &project;
    };


    
private:
    DialogManager(){
        mProjectDlg = new ProjectDialog;
        mArcTunnelChooseDlg = new ArcTunnelChooseDialog;
        mLineTunnelDlg = new LineTunnelDialog;
        mArcTunnelDlg = new ArcTunnelDialog;
        mInputParamsDlg = new InputParams;
        mResultDlg = new ResultDialog;     
    };
    ProjectDialog *mProjectDlg;
    ArcTunnelChooseDialog *mArcTunnelChooseDlg;
    LineTunnelDialog *mLineTunnelDlg;
    ArcTunnelDialog *mArcTunnelDlg;
    InputParams *mInputParamsDlg;
    ResultDialog *mResultDlg;
    Project *mProject = nullptr;
};

#endif // DIALOGMANAGER_H
