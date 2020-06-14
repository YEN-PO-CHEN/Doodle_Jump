#include "mainwindow.h"
#include "doodle.h"
#include "mainbullet.h"
#include <QApplication>
#include "_basic.h"
bool doodle::up_down = true;
int doodle::jump = 0;
vector<bool> mainbullet::bullet_of_number{true, true, true, true, true};
vector<int> mainbullet::pltfm_bool;
vector<QGraphicsPixmapItem *> mainbullet::pltfm_QItem;
int main(int argc, char *argv[])
{
    mainbullet::pltfm_bool.resize(Platform_NUM, 0);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
