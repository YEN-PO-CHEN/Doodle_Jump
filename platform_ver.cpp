#include "platform_ver.h"

platform_ver::platform_ver(QGraphicsScene *scene, int X, int Y, int mm) : platform(scene, X, Y), plt_now_number(mm) { add_pix(); }

void platform_ver::add_pix()
{
    pix_platform = QPixmap(":/rec/photo/platform/blue/p-dblue.png");
    pix_platform = pix_platform.scaled(Platform_X_SIZE, Platform_Y_SIZE);
    set_x_y();
}
void platform_ver::set_x_y()
{
    _pltfm.pltfm_QItem.at(plt_now_number) = new QGraphicsPixmapItem;
    put_into_the_scene();
}
void platform_ver::put_into_the_scene()
{
    _pltfm.pltfm_QItem.at(plt_now_number)->setPos(X_plt, Y_plt);
    _pltfm.pltfm_QItem.at(plt_now_number)->setPixmap(pix_platform);
    _pltfm.pltfm_bool.at(plt_now_number) = false;
    _scene->addItem(_pltfm.pltfm_QItem.at(plt_now_number));
}
