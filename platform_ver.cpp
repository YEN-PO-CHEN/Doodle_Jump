#include "platform_ver.h"

platform_ver::platform_ver() : platform(), pix_platform(QPixmap(":/rec/photo/platform/blue/p-dblue.png"))
{
}
void platform_ver::put_into_the_scene(int m)
{
    m = plt_now_number;
    _pltfm.pltfm_QItem.at(plt_now_number) = new QGraphicsPixmapItem;
    _pltfm.pltfm_QItem.at(plt_now_number)->setPixmap(pix_platform);
    _pltfm.pltfm_bool.at(plt_now_number) = false;

    _itemGroup->addToGroup(_pltfm.pltfm_QItem.at(plt_now_number));
}
