#include "monster4.h"

monster4::monster4(QGraphicsScene *I) : monster(I, 4)
{
    now = true;
    pix_sel();
}
void monster4::pix_sel()
{
    pix_i = QPixmap(":/rec/photo/monsters/monster_3left.png");
    pix_i = pix_i.scaled(0.5 * Platform_X_SIZE, Platform_X_SIZE);
    pix_re = QPixmap(":/rec/photo/monsters/monster_3right.png");
    pix_re = pix_re.scaled(0.5 * Platform_X_SIZE, Platform_X_SIZE);
    mon->setPixmap(pix_i);
    sle_x_y();
}
void monster4::sle_x_y()
{
    X = 0;
    Y = rand() % 100;
    Y = Scene_Y * (-2) - Y;
    add_sce();
}

void monster4::move_it()
{
    if (mon->x() < 0)
        now = true;
    if (mon->x() > Scene_X)
        now = false;
    if (now)
    {
        mon->setPixmap(pix_i);
        mon->setX(mon->x() + 2);
    }
    else
    {
        mon->setPixmap(pix_re);
        mon->setX(mon->x() - 2);
    }
}

void monster4::add_sce() {}
