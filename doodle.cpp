#include "doodle.h"

doodle::doodle(QGraphicsScene *mainwin, int i) : player(new QGraphicsPixmapItem),
                                                 type(i),
                                                 place_Y(Default_Y),
                                                 doodle_pos_X(Default_X),
                                                 doodle_pos_Y(Default_Y)
{
    //add if condition.
    doodle_pix = new QPixmap(":/rec/photo/player/scene1/L.png");
    player->setPos(doodle_pos_X, doodle_pos_Y);
    player->setPixmap(doodle_pix->scaled(Doodle_SIZE, Doodle_SIZE));
    mainwin->addItem(player);
}
void doodle::doodle_jump()
{
    int t = jump % 100;
    if (t == 0)
        doodle_pos_Y = Default_Y;
    if (t > 50)
    {
        t -= 50;
        double t_t = 2 * t + 1;
        double temp = (Doodle_acc * t_t) / 2.0;
        doodle_pos_Y += temp;
        this->player->setY(doodle_pos_Y);
    }
    else
    {
        double t_t = -1 * 2 * (t - 49) + 1;
        double temp = (Doodle_acc * t_t) / 2.0;
        doodle_pos_Y -= temp;
        this->player->setY(doodle_pos_Y);
    }
    ++jump;
}

void doodle::move_L()
{
    this->player->setPixmap(QPixmap(":/rec/photo/player/scene1/L.png"));
    if (doodle_pos_X < 0)
        doodle_pos_X += Scene_X;
    doodle_pos_X -= Move_By;
    this->player->setX(doodle_pos_X);
}

void doodle::move_R()
{
    this->player->setPixmap(QPixmap(":/rec/photo/player/scene1/R.png"));
    if (doodle_pos_X > Scene_X)
        doodle_pos_X -= Scene_X;
    doodle_pos_X += Move_By;
    this->player->setX(doodle_pos_X);
}
