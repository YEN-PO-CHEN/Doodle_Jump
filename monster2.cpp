#include "monster2.h"
//up_down
monster2::monster2(QGraphicsScene *I) : monster(I, 2) { pix_sel(); }

void monster2::pix_sel()
{
    pix_i = QPixmap(":/rec/photo/monsters/monster_1.png");
    pix_i = pix_i.scaled(Platform_X_SIZE, 0.5 * Platform_X_SIZE);
    mon->setPixmap(pix_i);
    sle_x_y();
}
void monster2::sle_x_y()
{
    int dy;
    int type;
    for (int k = 0; k < Platform_NUM; ++k)
        if (mainbullet::pltfm_bool.at(k) == 2)
            if (platform__build::v_platform.at(k)->plat->y() < dy)
            {
                dy = platform__build::v_platform.at(k)->plat->y();
                type = k;
            }
    X = platform__build::v_platform.at(type)->plat->x();
    Y = platform__build::v_platform.at(type)->plat->y() - Platform_Y_SIZE;
    add_sce();
}

void monster2::move_it()
{
    i %= 600;
    int k = i / 300;
    if (k == 1) //300-599
        mon->setX(mon->x() - 1);
    if (k == 0) //0-299
        mon->setX(mon->x() + 1);
    ++i;
}

void monster2::add_sce()
{
}
