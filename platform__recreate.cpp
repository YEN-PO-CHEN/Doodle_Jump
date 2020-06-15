#include "platform__recreate.h"
platform__recreate::platform__recreate(QGraphicsScene *I) : _scene(I) {}
//往上丟
void platform__recreate::plt_count()
{
    for (int plt_num = 0; plt_num < Platform_NUM; ++plt_num)
        if (platform__build::v_platform.at(plt_num)->plat->y() > (Scene_Y + 100))
            plt_recreate(plt_num);
}
void platform__recreate::plt_recreate(int I)
{
    int numX = rand() % (Scene_X - Platform_X_SIZE);
    int numY = rand() % 25;
    int dy = 0;
    for (int mm = 0; mm < Platform_NUM; ++mm)
        if (platform__build::v_platform.at(I)->plat->y() < dy)
            dy = platform__build::v_platform.at(I)->plat->y();
    numY = dy - numY - 150;
    platform__build::v_platform.at(I)->plat->setPos(numX, numY);
    platform__build::v_platform.at(I)->reback();
}
