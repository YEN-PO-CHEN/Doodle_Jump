#include "monster1.h"

monster1::monster1(QGraphicsScene * I):monster(I,1)
{
    QPixmap pix_i(":/rec/photo/monsters/bat.png");
    pix_i = pix_i.scaled(Platform_X_SIZE,2*Platform_X_SIZE);
    add_t_scene();
}
