#include "platform__recreate.h"
platform__recreate::platform__recreate(QGraphicsScene *I) : _scene(I) {}
//往上丟
void platform__recreate::plt_count()
{
    for (int plt_num = 0; plt_num < Platform_NUM; ++plt_num)
        if (platform__build::v_platform.at(plt_num)->plat->y() > (Scene_Y))
            plt_recreate(plt_num);
}
void platform__recreate::plt_recreate(int I)
{
    int numX = rand() % (Scene_X - Platform_X_SIZE);
    if (platform__build::v_platform.at(I)->plt_now_number == 2)
        numX = rand() % (Scene_X - 2 * Platform_X_SIZE);
    int numY = rand() % 25;
    int dy = 0;
    for (int mm = 0; mm < Platform_NUM; ++mm)
        if (platform__build::v_platform.at(mm)->plat->y() < dy)
            dy = platform__build::v_platform.at(mm)->plat->y();
    numY = dy + numY - 100;
    platform__build::v_platform.at(I)->plat->setPos(numX, numY);
    platform__build::v_platform.at(I)->reback();
}
