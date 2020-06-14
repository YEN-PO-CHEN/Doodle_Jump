#include "monster3.h"

monster3::monster3(QGraphicsScene * I):monster(I,3)
{
    QPixmap pix_i(":/rec/photo/monsters/monster_2.png");
    pix_i = pix_i.scaled(Platform_X_SIZE,Platform_X_SIZE);

}
