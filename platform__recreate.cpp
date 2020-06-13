#include "platform__recreate.h"

platform__recreate::platform__recreate(QGraphicsScene *I): _scene(I){}

void platform__recreate::move_the_platform(int A,int B){
    length = A;
    time_t = B;
    vel =length/time_t;
    connect(timer,SLOT(timeout()),this,SIGNAL(plat_move()));
    timer->start(10);
}

void platform__recreate::plat_move(){
    if(time_t == 0){
        timer->stop();
        return;
    }
    for(int a = 0;a<Platform_NUM;++a){
        int m = _main->pltfm_QItem.at(a)->y() + vel;
        _main->pltfm_QItem.at(a)->setY(m);
    }
    --time_t;
}
