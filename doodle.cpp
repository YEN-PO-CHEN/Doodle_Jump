#include "doodle.h"

doodle::doodle(QGraphicsScene *mainwin, int i) : ps_R(0),
                                                 ps_L(0),
                                                 doodle_pos_X(Default_X),
                                                 doodle_pos_Y(Default_Y),
                                                 type(i),
                                                 L_R(0),
                                                 place_Y(Default_Y),
                                                 player(new QGraphicsPixmapItem),
                                                 doodle_pix_type_1(new QPixmap(":/rec/photo/player/scene1/L.png")),
                                                 doodle_pix_type_2(new QPixmap(":/rec/photo/player/scene1/L.png")),
                                                 hor_int(new QTimer)
{
    //add if condition.
    player->setPos(doodle_pos_X, doodle_pos_Y);
    player->setPixmap(doodle_pix_type_1->scaled(Doodle_SIZE, Doodle_SIZE));
    mainwin->addItem(player);
}
void doodle::doodle_jump()
{
    int t = jump % Doodle_Jump_time_int;
    if (t == 0)
        doodle_pos_Y = Default_Y;
    if (t > (Doodle_Jump_time_int / 2))
    {
        t -= (Doodle_Jump_time_int / 2);
        double t_t = 2 * t + 1;
        double temp = (Doodle_vertical_acc * t_t) / 2.0;
        doodle_pos_Y += temp * (100.0 / Doodle_Jump_time);
        this->player->setY(doodle_pos_Y);
    }
    else
    {
        double t_t = -1 * 2 * (t - (Doodle_Jump_time_int / 2) + 1) + 1;
        double temp = (Doodle_vertical_acc * t_t) / 2.0;
        doodle_pos_Y -= temp * (100.0 / Doodle_Jump_time);
        this->player->setY(doodle_pos_Y);
    }
    ++jump;
}

void doodle::move_L()
{
    ++push_time_L;
    this->player->setPixmap(QPixmap(":/rec/photo/player/scene1/L.png"));
    doodle_test();
    doodle_pos_X -= Move_By;
    this->player->setX(doodle_pos_X);
    horizon_intercial(true);
    doodle_test();
    player->setX(doodle_pos_X);
}

void doodle::move_R()
{
    ++push_time_R;
    this->player->setPixmap(QPixmap(":/rec/photo/player/scene1/R.png"));
    doodle_test();
    doodle_pos_X += Move_By;
    this->player->setX(doodle_pos_X);
    horizon_intercial(false);
    doodle_test();
    this->player->setX(doodle_pos_X);
}

void doodle::horizon_intercial(bool direction)
{
    if (direction)
        L_R = -1;
    else
        L_R = 1; //R
    this->time = 0;
    if (!hor_int)
    {
        delete hor_int;
        hor_int = new QTimer;
    }
    this->hor_int->start(10);
    connect(hor_int, SIGNAL(timeout()), this, SLOT(ho_in()));
}
void doodle::ho_in()
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
    double vel = L_R * Doodle_horizonal_vel - (push_time_R - push_time_L) * Doodle_per_push * Doodle_vertical_acc;
    double acc = vel / Doodle_horizonal_run;

    position = vel - (acc / 2) * (2 * this->time + 1);
    doodle_pos_X += position;
    doodle_test();
    this->player->setX(doodle_pos_X);
}

void doodle::doodle_test()
{
    if (doodle_pos_X >= Scene_X - Doodle_SIZE * 0.5)
    {
        doodle_pos_X -= (Scene_X);
        doodle_pos_X -= Doodle_SIZE / 2;
    }
    if (doodle_pos_X < Doodle_SIZE * -1 * 0.5)
    {
        doodle_pos_X += Scene_X;
        doodle_pos_X += Doodle_SIZE / 2;
    }
}

void doodle::shot()
{
    this->player->setPixmap(QPixmap(":/rec/photo/player/scene1/S.png"));
    QTimer::singleShot(150, this, SLOT(aftershot()));
}
void doodle::aftershot()
{
    this->player->setPixmap(QPixmap(":/rec/photo/player/scene1/R.png"));
}
