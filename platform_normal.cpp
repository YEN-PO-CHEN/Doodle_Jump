#include "platform_normal.h"

platform_normal::platform_normal() : platform(),
                                     pix_platform(QPixmap(":/rec/photo/platform/green/p-green.png"))
{
}
void platform_normal::put_into_the_scene(int m)
{
    m = plt_now_number;
    _pltfm.pltfm_QItem.at(plt_now_number) = new QGraphicsPixmapItem;
    _pltfm.pltfm_QItem.at(plt_now_number)->setPixmap(pix_platform);
    _pltfm.pltfm_bool.at(plt_now_number) = false;
}
