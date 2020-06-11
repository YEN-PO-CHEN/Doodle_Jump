#include "mainwindow.h"
#include "doodle.h"
#include "mainbullet.h"
#include <QApplication>
bool doodle::up_down = true;
int doodle::jump = 0;
vector<bool> mainbullet::bullet_of_number{true, true, true, true, true};
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
