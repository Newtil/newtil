#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QWidget>

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = nullptr);
    ~SettingWindow();

private:
    Ui::SettingWindow *ui;

private slots:
    void toggledCloseWithoutSavingCheckBox(int);
    void saveSettings();
};

#endif // SETTINGWINDOW_H
