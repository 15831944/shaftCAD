QT       += core gui
RC_ICONS = project_easyicon_net_64.ico
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arctunnelchoosedialog.cpp \
    arctunneldialog.cpp \
    entity.cpp \
    inputparamsdialog.cpp \
    linetunneldialog.cpp \
    main.cpp \
    mainwindow.cpp \
    outloaddialog.cpp \
    project.cpp \
    projectdialog.cpp \
    resultdialog.cpp \
    shaft.cpp \
    toparcitem.cpp \
    tunnelchoosedialog.cpp

HEADERS += \
    DialogManager.h \
    SimpleIni.h \
    Utils.h \
    arctunnelchoosedialog.h \
    arctunneldialog.h \
    calculate.h \
    entity.h \
    inputparamsdialog.h \
    linetunneldialog.h \
    mainwindow.h \
    outloaddialog.h \
    project.h \
    projectdialog.h \
    resultdialog.h \
    shaft.h \
    toparcitem.h \
    tunnelchoosedialog.h

FORMS += \
    arctunnelchoosedialog.ui \
    arctunneldialog.ui \
    inputparamsdialog.ui \
    linetunneldialog.ui \
    mainwindow.ui \
    outloaddialog.ui \
    projectdialog.ui \
    resultdialog.ui \
    tunnelchoosedialog.ui

TRANSLATIONS += \
    xiejingbi_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc

msvc {
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}
