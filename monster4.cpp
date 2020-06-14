#include "monster4.h"

monster4::monster4(QGraphicsScene * I):monster(I,4)
{
    QPixmap pix_i(":/rec/photo/monsters/monster_left.png");
    pix_i = pix_i.scaled(Platform_X_SIZE,Platform_X_SIZE);
}
