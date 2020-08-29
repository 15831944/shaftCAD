#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QToolBar>
#include <QMenuBar>
#include <QCloseEvent>
#include <qtextcodec.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createMenus();
    void createActions();
    void createToolBars();
    //void loadFile(QString fileName);

public slots:
    void slotNewFile();
    void slotOpenFile();
    void slotSaveFile();
    void slotProjectInfo();

private:
    Ui::MainWindow *ui;

    QMenu *mFileMenu;
    QMenu *mProjectMenu;
    QMenu *mInputMenu;
    QMenu *mParamMenu;
    QMenu *mHelpMenu;

    QToolBar *mFileToolBar;
    QToolBar *mProjectToolBar;
    QToolBar *mHelpToolBar;

    QAction *mFileOpenAction;
    QAction *mFileNewAction;
    QAction *mFileSaveAction;
    QAction *mFileSaveAsAction;
    QAction *mExitAction;
    QAction *mProjectAction;
    QAction *mInputAction;
    QAction *mParamAction;
    QAction *mHelpAction;
    QAction *mCopyAction;
    QAction *mPastAction;
    QAction *mAboutAction;

    void InitMenuBar();
    void InitBg();

    void resizeEvent(QResizeEvent *event);
    void closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
