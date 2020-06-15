#include "doodle.h"
#include "mainwindow.h"
doodle::doodle(QGraphicsScene *mainwin, int i) :
    hor_int(new QTimer),
    player(new QGraphicsPixmapItem),
    ps_R(0),
    ps_L(0),
    doodle_pix_type{{QPixmap(":/rec/photo/player/scene1/L.png").scaled(Doodle_SIZE, Doodle_SIZE),
                     QPixmap(":/rec/photo/player/scene1/R.png").scaled(Doodle_SIZE, Doodle_SIZE),
                     QPixmap(":/rec/photo/player/scene1/S.png").scaled(Doodle_SIZE - 20, Doodle_SIZE + 20)}
                   ,{QPixmap(":/rec/photo/player/scene1/L.png").scaled(Doodle_SIZE, Doodle_SIZE),
                     QPixmap(":/rec/photo/player/scene1/R.png").scaled(Doodle_SIZE, Doodle_SIZE),
                     QPixmap(":/rec/photo/player/scene1/S.png").scaled(Doodle_SIZE - 20, Doodle_SIZE + 20)}},
    type(i-1),
    L_R(0)


{
    //Default Position
    player->setPos(Default_X, Default_Y);
    player->setPixmap(doodle_pix_type[type][0]);
    mainwin->addItem(player);

}
//X
void doodle::move_R() //SLOT
{
    ++push_time_R;
    player->setPixmap(doodle_pix_type[type][1]);
    doodle_test();
    horizon_intercial(false);
    doodle_test();
    player->setX(player->x() + Move_By);
}
void doodle::move_L() //SLOT
{
    ++push_time_L;
    player->setPixmap(doodle_pix_type[type][0]);
    doodle_test();
    horizon_intercial(true);
    doodle_test();
    player->setX(player->x() - Move_By);
}
void doodle::horizon_intercial(bool direction)
{
    if (direction)
        L_R = -1;
    else
        L_R = 1; //R
    time = 0;
    hor_int->stop();
    hor_int->start(10);
    connect(hor_int, SIGNAL(timeout()), this, SLOT(ho_in()));
}
void doodle::ho_in() //SLOT
{
    time++;
    if (time >= Doodle_horizonal_run)
    {
        delete hor_int;
        hor_int = new QTimer;
        time = 0;
        push_time_L = 0;
        push_time_R = 0;
        return;
    }
    position = 0;
    if (L_R == 1)
        --push_time_R;
    else
        --push_time_L;
    double vel = L_R * Doodle_horizonal_vel - (push_time_R - push_time_L) * Doodle_per_push * 0.5;
    double acc = vel / Doodle_horizonal_run;
    position = vel - (acc / 2) * (2 * this->time + 1);
    player->setX(player->x() + position);
    doodle_test();
}
void doodle::doodle_test() //X check
{
    if (player->x() >= Scene_X - Doodle_SIZE * 0.5)
    {
        player->setX(player->x() - (Scene_X));
        player->setX(player->x() - Doodle_SIZE / 2);
    }
    if (player->x() < Doodle_SIZE * -1 * 0.5)
    {
        player->setX(player->x() + (Scene_X));
        player->setX(player->x() + Doodle_SIZE / 2);
    }
}
//shoot
void doodle::shot()//
{
    player->setPixmap(doodle_pix_type[type][2]);
    QTimer::singleShot(150, this, SLOT(aftershot()));
}

void doodle::jump(double I){ player->setY(player->y()+ I); }
void doodle::aftershot() //SLOT
{ player->setPixmap(doodle_pix_type[type][1]); }
//y

