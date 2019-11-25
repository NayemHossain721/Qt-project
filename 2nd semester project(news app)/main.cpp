#include "mainwindow.h"
#include <QApplication>
#include<secdialog.h>
#include<thirddialog.h>
#include<QtWidgets>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow loginWindow;

       loginWindow.showMaximized();

       return a.exec();

}
