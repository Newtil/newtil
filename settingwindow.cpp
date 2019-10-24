#include "settingwindow.h"
#include "ui_settingwindow.h"

SettingWindow::SettingWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingWindow)
{
    ui->setupUi(this);
    setWindowFlag(Qt::Window);
    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->okButton, SIGNAL(clicked()), this, SLOT(saveSettings()));
    connect(ui->closeWithoutSaving, SIGNAL(stateChanged(int)), this, SLOT(toggledCloseWithoutSavingCheckBox(int)));
}

SettingWindow::~SettingWindow()
{
    delete ui;
}

void SettingWindow::toggledCloseWithoutSavingCheckBox(int state){
    if(state == Qt::Checked	){

    }
    else{

    }
}

void SettingWindow::saveSettings(){
    hide();
}
