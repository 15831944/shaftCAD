#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DialogManager.h"
#include "Utils.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    printf("main window create\n");
    showMaximized();
    InitBg();
    InitMenuBar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitBg(){
    setAutoFillBackground(true);
    QString path = ":bg/assets/background.png";
    QPalette mPalette = palette();
    QImage ImgAllBackground(path);
    QImage fitimagepic = ImgAllBackground.scaled(width(), height(), Qt::IgnoreAspectRatio);
    mPalette.setBrush(QPalette::Window, QBrush(fitimagepic));
    setPalette(mPalette);
}

void MainWindow::resizeEvent(QResizeEvent *event){
    InitBg();
}



void MainWindow::createMenus(){

    printf("create menus method\n");

    mFileMenu=menuBar()->addMenu("文件");
    mFileMenu->addAction(mFileOpenAction);
    mFileMenu->addAction(mFileNewAction);
    mFileMenu->addAction(mFileSaveAction);
//    mFileMenu->addAction(mExitAction);

    mProjectMenu = menuBar()->addMenu("工程模板信息");
    mProjectMenu->addAction(mProjectAction);

    mInputMenu = menuBar()->addMenu("参数录入");

    mParamMenu = menuBar()->addMenu("参数设置");

    mHelpMenu = menuBar()->addMenu("帮助");
    //mHelpMenu->addAction(mAboutAction);
}

void MainWindow::InitMenuBar(){
   printf("init menu bar method\n");
   createActions();
   createMenus();
   createToolBars();
}

void MainWindow::createActions(){

    QFont actionFont("Microsoft YaHei UI", 12);

    mFileNewAction = new QAction(QIcon(":icon/assets/icon-toolbar/new_file.png"), tr("新建"), this);
    mFileNewAction->setShortcut(tr("Ctrl+N"));
    mFileNewAction->setStatusTip("新建文件");
    mFileNewAction->setFont(actionFont);
    connect(mFileNewAction, SIGNAL(triggered()), this, SLOT(slotNewFile()));

    mFileOpenAction = new QAction(QIcon(":icon/assets/icon-toolbar/open_file.png"),tr("打开"), this);
    mFileOpenAction->setShortcut(tr("Ctrl+O"));
    mFileOpenAction->setStatusTip(tr("打开文件"));
     mFileOpenAction->setFont(actionFont);
    connect(mFileOpenAction, SIGNAL(triggered()), this, SLOT(slotOpenFile()));

    mFileSaveAction = new QAction(QIcon(":icon/assets/icon-toolbar/save.png"), tr("保存"), this);
    mFileSaveAction->setShortcut(tr("Ctrl+S"));
    mFileSaveAction->setStatusTip("保存文件");
     mFileSaveAction->setFont(actionFont);
    connect(mFileSaveAction, SIGNAL(triggered()), this, SLOT(slotSaveFile()));

    mExitAction = new QAction(tr("退出"), this);
    mExitAction->setShortcut(tr("Ctrl+Q"));
    mExitAction->setStatusTip("退出");
    connect(mExitAction, SIGNAL(triggered()), this, SLOT(close()));

    mFileSaveAsAction = new QAction(QIcon(":icon/assets/icon-toolbar/saveas.png"), tr("另存为"), this);
    mProjectAction = new QAction(QIcon(":icon/assets/icon-toolbar/project_info.png"), tr("工程信息"), this);
    connect(mProjectAction, SIGNAL(triggered()), this, SLOT(slotProjectInfo()));

    mInputAction = new QAction(QIcon(":icon/assets/icon-toolbar/input.png"), tr("输入"),this);
    mParamAction = new QAction(QIcon(":icon/assets/icon-toolbar/param.png"), tr("设置"), this);
    mHelpAction = new QAction(QIcon(":icon/assets/icon-toolbar/help.png"), tr("帮助"),this);
}

void MainWindow::createToolBars(){

    mFileToolBar = addToolBar("文件");

    mFileToolBar->addAction(mFileNewAction);
    mFileToolBar->addAction(mFileOpenAction);
    mFileToolBar->addAction(mFileSaveAction);
    mFileToolBar->addAction(mFileSaveAsAction);


    mProjectToolBar = addToolBar("工程");
    mProjectToolBar->addAction(mProjectAction);
    mProjectToolBar->addAction(mInputAction);
    mProjectToolBar->addAction(mParamAction);

    mHelpToolBar = addToolBar("帮助");
    mHelpToolBar->addAction(mHelpAction);

}

void MainWindow::slotNewFile(){
    DialogManager::GetInstance().ShowProjectDialog();
}

void MainWindow::slotOpenFile(){
    QString filename = QFileDialog::getOpenFileName(this);
    if(!filename.isEmpty()){
        QMessageBox::information(NULL, "Message", "打开文件");
    }
}

void MainWindow::slotSaveFile(){
    printf("save file\n");
}

void MainWindow::slotProjectInfo()
{
    DialogManager::GetInstance().ShowProjectDialog();
}



void MainWindow::closeEvent(QCloseEvent *event){
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, tr("退出"), QString(tr("确认退出程序?")),
                                   QMessageBox::Yes|QMessageBox::No);
    if(button == QMessageBox::No){
        event->ignore();
    }else if (button == QMessageBox::Yes){

       CADService::RemoveAcadRx();
        event->accept();
    }
}

