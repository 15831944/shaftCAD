#ifndef PROJECT_H
#define PROJECT_H
#include <QString>
#include "shaft.h"
#include <iostream>
#include <string>
#include "atlstr.h"
#include "SimpleIni.h"
using namespace std;

class Project
{

private:
    std::string mTitle;
    std::string mDescription;
    std::string mScaleNumber;
    std::string mPaperNumber;
    std::string mPaperSize;

    std::string mDesigner;
    std::string mDate;
    std::string mChecker;
    std::string mCheckDate;
    std::string mDesignApart;

    Shaft *mShaft = nullptr;


    bool SaveTopVector(CString file);
    bool SaveWallVector(CString file);
    bool SaveTunnelToFile(CString filename);
    bool SaveBottomVector(CString file);
    bool SaveProjectInfo(CString filename);


    void ReadTunnel(CSimpleIni mProjectIni);

    bool hasOpendFile = false;
    bool isEdited = false;

public:
    Project();


    // 将工程信息写入桥接文件中
    bool ProjectSaver(CString filename);

    // 读取工程信息到程序中，并用于计算；
    bool ProjectReader(CString filename);

    // 当巷道参数被选择时调用此方法
    void NewShaft(){
        mShaft = new Shaft();
    };

    Shaft* GetShaft() const {return mShaft;};
    void SetShaft(Shaft &shaft){mShaft = &shaft;};

    void SetTitle(QString title){

        mTitle = title.toStdString();
        std::cout << "set title, mTitle: " << mTitle << std::endl;
    };
    string GetTitle() const {return mTitle;};
    void SetDescription(QString description){
        mDescription = description.toStdString();
    };
    string GetDescription() const {return mDescription;};
    void SetScaleNumber(QString number){
        mScaleNumber = number.toStdString();
    };
    string GetScaleNumber() const {return mScaleNumber;};
    void SetPaperNumber(QString number){
        mPaperNumber = number.toStdString();
    };
    string GetPaperNumber() const {return mPaperNumber;};
    void SetPaperSize(QString size){
        mPaperSize = size.toStdString();
    };
    string GetPaperSize() const {return mPaperSize;};
    void SetDesigner(QString designer){ mDesigner = designer.toStdString();};
    string GetDesigner() const {return mDesigner;};
    void SetDate(QString date){ mDate = date.toStdString();};
    string GetDate() const {return mDate;};
    void SetChecker(QString checker){mChecker = checker.toStdString();};
    string GetChecker() const {return mChecker;};
    void SetCheckDate(QString date){mCheckDate = date.toStdString();};
    string GetCheckDate() const {return mCheckDate;};
    void SetDesignApart(QString apart) { mDesignApart = apart.toStdString();};
    string GetDesignApart() const {return mDesignApart;};

};

#endif // PROJECT_H
