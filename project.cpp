#include "project.h"
#include "project.h"
#include <iostream>
Project::Project()
{

}

CString itocstr(int i)
{
    CString str;
    str.Format(_T("%d"), i);
    return str;
}

bool Project::ProjectSaver(CString filename)
{

    std::cout << "call project saver" << std::endl;

    return  SaveTunnelToFile(filename) && SaveTopVector(filename)
            && SaveWallVector(filename) && SaveBottomVector(filename);
}


bool Project::SaveProjectInfo(CString filename){

    CSimpleIni mProjectIni;

    SI_Error rc = mProjectIni.LoadFile(filename);
    if (rc < 0) {
        printf("Error in SaveTunnelToFile: Fail to load file!\n");

        return false; // 若加载文件出错，返回false
    }
    const wchar_t *strArc = L"Project";
    const wchar_t *strPaperTitle = L"PaperTitle";
    const wchar_t *strPaperDescription = L"PaperDescription";
    const wchar_t *strScaleNumber = L"ScaleNumber";
    const wchar_t *strPaperSize = L"PaperSize";
    const wchar_t *strPaperNumber = L"PaperNumber";

    const wchar_t *strDesigner = L"Designer";
    const wchar_t *strDate = L"Date";
    const wchar_t *strChecker = L"Checker";
    const wchar_t * strCheckDate = L"CheckDate";
    const wchar_t * strDesignApart = L"DesignApart";
    const wchar_t * strDevelopApart = L"DevelopApart";

    mProjectIni.SetValue( strArc, strPaperTitle, wstring(mTitle.begin(), mTitle.end()).c_str());
    mProjectIni.SetValue( strArc, strPaperDescription, wstring(mDescription.begin(), mDescription.end()).c_str());
    mProjectIni.SetValue( strArc, strScaleNumber, wstring(mScaleNumber.begin(), mScaleNumber.end()).c_str());
    mProjectIni.SetValue( strArc, strPaperSize, wstring(mPaperSize.begin(), mPaperSize.end()).c_str());
    mProjectIni.SetValue( strArc, strPaperNumber, wstring(mPaperNumber.begin(), mPaperNumber.end()).c_str());

    mProjectIni.SetValue( strArc, strDesigner, wstring(mDesigner.begin(), mDesigner.end()).c_str());
    mProjectIni.SetValue( strArc, strDate, wstring(mDate.begin(), mDate.end()).c_str());
    mProjectIni.SetValue( strArc, strChecker, wstring(mChecker.begin(), mChecker.end()).c_str());
    mProjectIni.SetValue( strArc, strCheckDate, wstring(mCheckDate.begin(), mCheckDate.end()).c_str());
    mProjectIni.SetValue( strArc, strDesignApart, wstring(mDesignApart.begin(), mDesignApart.end()).c_str());
    mProjectIni.SetValue( strArc, strDevelopApart, L"西安科技大学");

    SI_Error rc2 = mProjectIni.SaveFile(filename);
    return rc2 < 0 ? false : true;
}


bool Project::SaveTunnelToFile(CString filename){

    CSimpleIni mProjectIni;


    SI_Error rc = mProjectIni.LoadFile(filename);
    if (rc < 0) {
        printf("Error in SaveTunnelToFile: Fail to load file!\n");

        return false; // 若加载文件出错，返回false
    }
    const wchar_t *strArc = L"Arc";
    const wchar_t *strTopArcRadius = L"TopArcRadius";
    const wchar_t *strWallHeight = L"WallHeight";
    const wchar_t *strNormal = L"IsBottomArc";
    const wchar_t *strBottomArcR = L"BottomArcR";

    mProjectIni.SetDoubleValue( strArc, strTopArcRadius, mShaft->GetHalfCircleR());
    mProjectIni.SetDoubleValue(strArc, strWallHeight, mShaft->GetWallHeight());
    mProjectIni.SetBoolValue(strArc, strNormal, mShaft->GetIsBottomArc());
    if(mShaft->GetIsBottomArc()){
        mProjectIni.SetDoubleValue(strArc, strBottomArcR, mShaft->GetBottomArcR());
    }

    SI_Error rc2 = mProjectIni.SaveFile(filename);
    return rc2 < 0 ? false : true;
}

bool Project::SaveTopVector(CString file)
{
    CSimpleIni mProjectIni;


    SI_Error rc = mProjectIni.LoadFile(file);
    if (rc < 0)
    {

        printf("Error in SaveTopVector: Fail to load file!");
        return false; // 若加载文件出错，返回false

    }

    const wchar_t *strTopVectorM = L"TopVectorWanju";
    const wchar_t *strTopVectorN = L"TopVectorZhouli";
    for(TopArcItem it: mShaft->getVecTop()){



        mProjectIni.SetDoubleValue(strTopVectorM,
                                   itocstr(it.getId()),
                                   it.getM_wanju());
        mProjectIni.SetDoubleValue(strTopVectorN,
                                  itocstr(it.getId()),
                                   it.getN_zhouli());
    }

    SI_Error rc2 = mProjectIni.SaveFile(file);
    return rc2 < 0 ? false : true;
}

bool Project::SaveWallVector(CString file)
{
    CSimpleIni mProjectIni;


    SI_Error rc = mProjectIni.LoadFile(file);
    if (rc < 0)
    {
        printf("Error in SaveWallVector: Fail to load file!");
        return false; // 若加载文件出错，返回false
    }
   const wchar_t *strWallVectorM = L"WallVectorWanju";
   const wchar_t *strWallVectorN = L"WallVectorZhouli";
   for(WallItem it: mShaft->getVecWall()){

       mProjectIni.SetDoubleValue(strWallVectorM,
                                  itocstr(it.getId()),
                                  it.getM_wanju());
       mProjectIni.SetDoubleValue(strWallVectorN,
                                  itocstr(it.getId()),
                                  it.getQ_zhouli());
   }

    SI_Error rc2 = mProjectIni.SaveFile(file);
    return rc2 < 0 ? false : true;
}

bool Project::SaveBottomVector(CString file)
{
    CSimpleIni mProjectIni;

    SI_Error rc = mProjectIni.LoadFile(file);
    if (rc < 0)
    {
        printf("Error in SaveBottomVector: Fail to load file!");
        return false; // 若加载文件出错，返回false
    }
    const wchar_t *strBottomVectorM = L"BottomVectorWanju";
       const wchar_t *strBottomVectorN = L"BottomVectorZhouli";
    for(BottomItem it: mShaft->getVecBottom()){

        mProjectIni.SetDoubleValue(strBottomVectorM,
                                   itocstr(it.getId()),
                                   it.getM_Wanju());
        mProjectIni.SetDoubleValue(strBottomVectorN,
                                   itocstr(it.getId()),
                                   it.getQ_Zhouli());
    }

    SI_Error rc2 = mProjectIni.SaveFile(file);
    return rc2 < 0 ? false : true;
}

bool Project::ProjectReader(CString filename){

    CSimpleIni mProjectIni;

    SI_Error rc = mProjectIni.LoadFile(filename);
    if (rc < 0) {
        printf("Error in SaveTunnelToFile: Fail to load file!\n");

        return false; // 若加载文件出错，返回false
    }



}

void Project::ReadTunnel(CSimpleIni mProjectIni)
{

    NewShaft();

    const wchar_t *strArc = L"Arc";
    const wchar_t *strTopArcRadius = L"TopArcRadius";
    const wchar_t *strWallHeight = L"WallHeight";
    const wchar_t *strNormal = L"IsBottomArc";
    const wchar_t *strBottomArcR = L"BottomArcR";

    mShaft->SetWallHeight(mProjectIni.GetDoubleValue(strArc, strWallHeight));
    mShaft->SetHalfCircleR(mProjectIni.GetDoubleValue(strArc, strTopArcRadius));
    mShaft->SetIsBottomArc(mProjectIni.GetBoolValue(strArc, strNormal));
    if(mShaft->GetIsBottomArc() == true){
        mShaft->SetBottomArcR(mProjectIni.GetDoubleValue(strArc, strBottomArcR));
    }

}

