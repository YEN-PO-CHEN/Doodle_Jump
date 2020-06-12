#include "platform_hor.h"

platform_hor::platform_hor() : platform() { add_pix(); }
platform_hor::platform_hor(int X, int Y) : platform(X, Y) { add_pix(); }
void platform_hor::put_into_the_scene(int m)
{
    plt_now_number = m;
    _pltfm.pltfm_QItem.at(plt_now_number) = new QGraphicsPixmapItem;
    _pltfm.pltfm_QItem.at(plt_now_number)->setPixmap(pix_platform);
    _pltfm.pltfm_bool.at(plt_now_number) = false;
}
void platform_hor::add_pix()
{
    pix_platform = QPixmap(":/rec/photo/platform/blue/platform-blue.png");
    pix_platform = pix_platform.scaled(Platform_X_SIZE, Platform_Y_SIZE);
}
void platform_hor::set_x_y(){
    _pltfm.pltfm_QItem.at(plt_now_number)->setPos(X_plt,Y_plt);
}
