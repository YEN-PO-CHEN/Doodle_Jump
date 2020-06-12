#include "platform_broken.h"

platform_broken::platform_broken(QGraphicsScene *scene, int X, int Y, int mm) : platform(scene, X, Y), plt_now_number(mm) { add_pix(); }

void platform_broken::add_pix()
{
    pix_platform[0] = QPixmap(":/rec/photo/platform/brown/platform_brown.png");
    pix_platform[1] = QPixmap(":/rec/photo/platform/brown/platform_brown_broken.png");
    for (int i = 0; i < 2; ++i)
        pix_platform[i] = pix_platform[i].scaled(Platform_X_SIZE, Platform_Y_SIZE);
    set_x_y();
}
void platform_broken::set_x_y()
{
    _pltfm.pltfm_QItem.at(plt_now_number) = new QGraphicsPixmapItem;
    put_into_the_scene();
}
void platform_broken::put_into_the_scene()
{
    _pltfm.pltfm_QItem.at(plt_now_number)->setPos(X_plt, Y_plt);
    _pltfm.pltfm_QItem.at(plt_now_number)->setPixmap(pix_platform[0]);
    _pltfm.pltfm_bool.at(plt_now_number) = false;
    _scene->addItem(_pltfm.pltfm_QItem.at(plt_now_number));
}
