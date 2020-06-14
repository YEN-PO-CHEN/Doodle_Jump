#include "platform__recreate.h"
platform__recreate::platform__recreate(QGraphicsScene *I) : _scene(I), timer(new QTimer){ v_platform.resize(Platform_NUM); }
void platform__recreate::move_the_platform(int A, int B,int C)
{
    length = A;
    length = DOODLE_HIGH - length + Platform_Y_SIZE;
    time_t = 120 - B;
    time_s = 0;
    a = 2*(static_cast<double>(length))/((static_cast<double>(time_t))*(static_cast<double>(time_t)));
    //cout<<DOODLE_ACC<<endl;
}
void platform__recreate::plat_move()
{

    //cout<<time_t<<endl;
    if(time_s == time_t){ timer->stop(); emit restart(); }
    for (int mmm = 0; mmm < Platform_NUM; ++mmm)
    {        
        double len = 0.5*a*(2*time_s+1);
        //cout<<len<<endl;
        len = _main->pltfm_QItem.at(mmm)->y() + len;
        _main->pltfm_QItem.at(mmm)->setY(len);
        cout<<len<<endl;
    }

    ++time_s;
    plt_count();

}
void platform__recreate::plt_count()
{
    for (int plt_num = 0; plt_num < Platform_NUM; ++plt_num)
        if (_main->pltfm_QItem.at(plt_num)->y() > (Scene_Y+100))
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
    int numY = rand() % 25;
    int dy = 0;
    for(int mm = 0;mm<Platform_NUM;++mm)
        if(_main->pltfm_QItem.at(mm)->y() < dy)
            dy = _main->pltfm_QItem.at(mm)->y();
    numY = dy - numY - 150;
    _main->pltfm_QItem.at(I)->setPos(numX, numY);

    if(_main->pltfm_bool.at(I) == 1){
        _main->pltfm_QItem.at(I)->setZValue(0);
        _main->pltfm_QItem.at(I)->setPixmap(QPixmap(":/rec/photo/platform/brown/platform_brown.png"));
    }
}
void platform__recreate::start_move(){timer->start(10);}
