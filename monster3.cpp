#include "monster3.h"
//left_right
monster3::monster3(QGraphicsScene *I) : monster(I, 3) { pix_sel(); }

void monster3::pix_sel()
{
    pix_i = QPixmap(":/rec/photo/monsters/bat.png");
    pix_i = pix_i.scaled(Platform_X_SIZE, 0.5 * Platform_X_SIZE);
    mon->setPixmap(pix_i);
    sle_x_y();
}

void monster3::sle_x_y()
{
    int dy;
    int type;
    for (int k = 0; k < Platform_NUM; ++k)
        if (mainbullet::pltfm_bool.at(k) == 3)
            if (platform__build::v_platform.at(k)->plat->y() < dy)
            {
                dy = platform__build::v_platform.at(k)->plat->y();
                type = k;
            }
    Y = platform__build::v_platform.at(type)->plat->y() - 0.5 * Platform_X_SIZE;
    X = platform__build::v_platform.at(type)->plat->x();
    add_sce();
}

void monster3::move_it()
{
    i %= 600;
    int m = i / 300;
    if (m == 0)
        mon->setY(mon->y() + 1);
    else
        mon->setY(mon->y() - 1);
    ++i;
}

void monster3::add_sce() {}
