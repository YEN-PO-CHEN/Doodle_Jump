#include "platform__recreate.h"
platform__recreate::platform__recreate(QGraphicsScene *I) : _scene(I), timer(new QTimer){ v_platform.resize(Platform_NUM); }
void platform__recreate::move_the_platform(int A, int B,int C)
{
    length = A;
    time_t = B;
    now_item = C;
    vel = length / time_t;
    timer->start(5);
}
void platform__recreate::plat_move()
{
    if(_main->pltfm_QItem.at(now_item)->y() > Default_Y){ timer->stop(); }
    for (int a = 0; a < Platform_NUM; ++a)
    {
        int m = _main->pltfm_QItem.at(a)->y() + vel;
        _main->pltfm_QItem.at(a)->setY(m);
    }
    plt_count();
}
void platform__recreate::plt_count()
{
    for (int plt_num = 0; plt_num < Platform_NUM; ++plt_num)
        if (_main->pltfm_QItem.at(plt_num)->y() > Scene_Y)
            plt_recreate(plt_num);
}
void platform__recreate::plt_recreate(int I)
{
    int K = I;
    if (K == 0)
        K = Platform_NUM - 1;
    else
        --K;
    int numX = rand() % (Scene_X - Platform_X_SIZE);
    int numY = rand() % 60;
    numY += 70;
    numY += Platform_Y_SIZE;
    numY = _main->pltfm_QItem.at(K)->y() - numY;
    _main->pltfm_QItem.at(I)->setPos(numX, numY);
}
