#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    config.setIniCodec(QTextCodec::codecForName("UTF-8"));
    setting = new SettingWindow(this);

    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(closeFile()));
    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(newFile()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionSave_as, SIGNAL(triggered()), this, SLOT(saveAsFile()));
    connect(ui->actionSettings, SIGNAL(triggered()), this, SLOT(openSettings()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete setting;
}

void MainWindow::openFile(){
    QString sellectedFilter;
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open file"),
        "C:/",
        tr("pie project file(*.piep)"),
        &sellectedFilter,
        QFileDialog::DontUseCustomDirectoryIcons
    );
    if (fileName.isEmpty()) {
        // cancel
    }

}

void MainWindow::closeFile(){
    int res = QMessageBox::question(this, tr("Pie"), tr("Close without saving?"));
    if (res == QMessageBox::No) return;

    // close file
}

void MainWindow::newFile(){

}

void MainWindow::saveFile(){
    if(neverSaved){
        saveAsFile();
        return;
    }
    // save file
}

void MainWindow::saveAsFile(){
    QString sellectedFilter;
    QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("Save as"),
        ".",
        tr("pie project file(*.piep)"),
        &sellectedFilter,
        QFileDialog::DontUseCustomDirectoryIcons
    );
    if (fileName.isEmpty()) {
        // cancel
    }
}

void MainWindow::openSettings(){
    setting->show();
}

void MainWindow::closeEvent(QCloseEvent *event){
    int res = QMessageBox::question(this, tr("Pie"), tr("Exit without saving?"));
    if (res == QMessageBox::No) event->ignore();
}

