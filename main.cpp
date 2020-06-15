#include "mainwindow.h"
#include "doodle.h"
#include "mainbullet.h"
#include <QApplication>
#include "_basic.h"
#include "platform.h"
vector<bool> mainbullet::bullet_of_number{true, true, true, true, true};
vector<int> mainbullet::pltfm_bool{};
vector<platform *> platform__build::v_platform{};
int main(int argc, char *argv[])
{
    mainbullet::pltfm_bool.resize(Bullet_NUM, 0);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
