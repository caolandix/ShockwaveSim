#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication theApp(argc, argv);
    MainWindow mainWnd;
    mainWnd.show();

    return theApp.exec();
}
