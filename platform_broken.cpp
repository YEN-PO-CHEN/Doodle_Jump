#include "platform_broken.h"

platform_broken::platform_broken() : platform(),
                                     pix_platform{(QPixmap(":/rec/photo/platform/brown/platform_brown.png")),
                                                  (QPixmap(":/rec/photo/platform/brown/platform_brown_broken.png"))}
{
    for (int i = 0; i < 2; ++i)
        pix_platform[i] = pix_platform[i].scaled(Platform_X_SIZE, Platform_Y_SIZE);
}
void platform_broken::put_into_the_scene(int m)
{
    m = plt_now_number;
    _pltfm.pltfm_QItem.at(plt_now_number) = new QGraphicsPixmapItem;
    _pltfm.pltfm_QItem.at(plt_now_number)->setPixmap(pix_platform[0]);
    _pltfm.pltfm_bool.at(plt_now_number) = false;
}
