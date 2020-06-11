#include "platform_ver.h"

platform_ver::platform_ver() : platform() { add_pix(); }
platform_ver::platform_ver(int X, int Y) : platform(X, Y) { add_pix(); }
void platform_ver::put_into_the_scene(int m)
{
    plt_now_number = m;
    _pltfm.pltfm_QItem.at(plt_now_number) = new QGraphicsPixmapItem;
    _pltfm.pltfm_QItem.at(plt_now_number)->setPixmap(pix_platform);
    _pltfm.pltfm_bool.at(plt_now_number) = false;

    _itemGroup->addToGroup(_pltfm.pltfm_QItem.at(plt_now_number));
}
void platform_ver::add_pix()
{
    pix_platform = QPixmap(":/rec/photo/platform/blue/p-dblue.png");
    pix_platform = pix_platform.scaled(Platform_X_SIZE, Platform_Y_SIZE);
}
