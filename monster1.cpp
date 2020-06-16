#include "monster1.h"
//stop
monster1::monster1(QGraphicsScene *I) : monster(I, 1) { pix_sel(); }

void monster1::pix_sel()
{
    pix_i = QPixmap(":/rec/photo/monsters/monster_2.png");
    pix_i = pix_i.scaled(Platform_X_SIZE, Platform_X_SIZE);
    mon->setPixmap(pix_i);
    sle_x_y();
}

void monster1::sle_x_y()
{
    Y = rand() % 100;
    Y = Scene_Y * (-2) - Y;
    X = rand() % (Scene_X - 3 * Platform_X_SIZE);
    add_sce();
}

void monster1::add_sce()
{
}
