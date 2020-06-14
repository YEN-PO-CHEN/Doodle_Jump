#include "monster2.h"

monster2::monster2(QGraphicsScene * I):monster(I,2)
{
    QPixmap pix_i(":/rec/photo/monsters/monster_1.png");
    pix_i = pix_i.scaled(Platform_X_SIZE,2*Platform_X_SIZE);
}
