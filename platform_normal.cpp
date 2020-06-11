#include "platform_normal.h"

platform_normal::platform_normal() : platform() { add_pix(); }
platform_normal::platform_normal(int X, int Y) : platform(X, Y) { add_pix(); }
void platform_normal::put_into_the_scene(int m)
{
    plt_now_number = m;
    _pltfm.pltfm_QItem.at(plt_now_number) = new QGraphicsPixmapItem;
    _pltfm.pltfm_QItem.at(plt_now_number)->setPixmap(pix_platform);
    _pltfm.pltfm_bool.at(plt_now_number) = false;
}
void platform_normal::add_pix()
{
    pix_platform = QPixmap(":/rec/photo/platform/green/p-green.png");
    pix_platform = pix_platform.scaled(Platform_X_SIZE, Platform_Y_SIZE);
}
