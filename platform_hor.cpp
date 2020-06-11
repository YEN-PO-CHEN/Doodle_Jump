#include "platform_hor.h"

platform_hor::platform_hor() : platform(), pix_platform(QPixmap(":/rec/photo/platform/blue/platform-blue.png"))
{
}
void platform_hor::put_into_the_scene(int m)
{
    m = plt_now_number;
    _pltfm.pltfm_QItem.at(plt_now_number) = new QGraphicsPixmapItem;
    _pltfm.pltfm_QItem.at(plt_now_number)->setPixmap(pix_platform);
    _pltfm.pltfm_bool.at(plt_now_number) = false;
}
