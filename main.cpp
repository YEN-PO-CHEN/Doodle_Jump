#include "mainwindow.h"
#include "doodle.h"
#include <QApplication>

int doodle::jump = 0;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
