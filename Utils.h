#pragma once
#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <QString>
#include <QFile>
#include <atlstr.h>
#include <Windows.h>

#include <QtCore>


class Utils{
public:

    static CString QS2CS(QString qs) {
        return qs.toStdString().c_str();
    };

    static QString CS2QS(CString cs){
        return QString::fromWCharArray((LPCTSTR)cs, cs.GetLength());
    };

    static CString itostr(int i)
    {
        CString str;
        str.Format(_T("%d"), i);
        return str;
    };


};


class CADService {

public:

    static CString GetAcad2017Path() {

        CString strAppName("SOFTWARE\\Autodesk\\AutoCAD\\R21.0\\ACAD-0001\\Install");
            std::cout << strAppName.GetString() << std::endl;
            HKEY hKey;
            CString strAppRegeditPath("");
            TCHAR szProductType[MAX_PATH];
            memset(szProductType, 0, sizeof(szProductType));

            DWORD dwBuflen = MAX_PATH;
            LONG lRet = 0;

            // 打开注册表，只有打开后才能进行其他操作
            lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE, //要打开的根键
                LPCTSTR(strAppName), // 要打开的子键
                0, //这个一定为0
                KEY_WOW64_64KEY | KEY_QUERY_VALUE,//指定打开方式为读
                &hKey
            );

            std::cout << "lret: " << lRet << std::endl;
            if (lRet != ERROR_SUCCESS)
            {
                printf("open error!\n");
                return strAppRegeditPath;
            }
            else
            {
                // 下面开始查询
                lRet = RegQueryValueEx(hKey, //打开注册表时返回的句柄
                    TEXT("INSTALLDIR"), //要查询的名称
                    NULL, NULL,
                    (LPBYTE)szProductType,
                    &dwBuflen);
            }
            if (lRet != ERROR_SUCCESS)
            {
                printf("read error!\n");

                return strAppRegeditPath;
            }
            else
            {
                RegCloseKey(hKey);
                strAppRegeditPath = szProductType;
            }
            std::cout << strAppRegeditPath.GetString() << std::endl;
            return strAppRegeditPath;
    };


    //编写acad.rx 文件
    static BOOL WriteAcadRx() {

        QString filename = Utils::CS2QS(GetAcad2017Path()) + "acad.rx";

        std::cout << "arax rx filename: " << filename.toStdString() << std::endl;

        QFile file(filename);

        if(file.open(QIODevice::ReadWrite|QIODevice::Text)){
            file.write("INGExiejingcad.arx");
            file.flush();
            file.close();
            return TRUE;
        }

        else return FALSE;

    };

    static bool RemoveAcadRx(){
        QString filename =  Utils::CS2QS(GetAcad2017Path()) + "acad.rx";
        QFile file(filename);
        bool status = file.remove();
        std::cout <<"remove acad rx: " << status << std::endl;
        return status;
    }




    // 通过创建进程的方式启动 acad.exe
    static BOOL LaunchACad() {
        CString OutputPath;
        CString m_strCADPath = GetAcad2017Path(); //从注册表中获取 acad 2017的路径
        STARTUPINFO si; //一些必备参数设置
        memset(&si, 0, sizeof(STARTUPINFO));
        si.cb = sizeof(STARTUPINFO);
        si.dwFlags = STARTF_USESHOWWINDOW;
        si.wShowWindow = SW_SHOWNORMAL;
        PROCESS_INFORMATION pi; //必备参数设置结束
        OutputPath = m_strCADPath + "acad.exe";
        BOOL bRet = CreateProcess(NULL, OutputPath.GetBuffer(OutputPath.GetLength()),
                                  NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

        return bRet;
    };

};

#endif // UTILS_H
