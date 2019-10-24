#include "mainwindow.h"

#include <QApplication>

// avoid misconversion (Japanese chacters)
#define TR(s) (QString::fromLocal8Bit(s))

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
