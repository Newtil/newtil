#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QMessageBox>
#include <QFileDialog>
#include <QSettings>
#include <QTextCodec>

#include "settingwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SettingWindow *setting;
    bool neverSaved = true;
    QSettings config{"pie.ini", QSettings::IniFormat};
    void closeEvent(QCloseEvent *);

private slots:
    void openFile();
    void closeFile();
    void newFile();
    void saveFile();
    void saveAsFile();
    void openSettings();
};
#endif // MAINWINDOW_H
