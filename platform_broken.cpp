#include "platform_broken.h"

platform_broken::platform_broken(QGraphicsScene *scene, int X, int Y, int mm) : platform(scene, X, Y, mm) { add_pix(); }
void platform_broken::add_pix()
{
    pix_platform = QPixmap(":/rec/photo/platform/brown/platform_brown.png").scaled(Platform_X_SIZE, Platform_Y_SIZE);
    pix_platform_sp = QPixmap(":/rec/photo/platform/brown/platform_brown_broken.png").scaled(Platform_X_SIZE, Platform_Y_SIZE);
    set_x_y();
}
void platform_broken::change()
{
    plat->setY(plat->y() + 10);
    plat->setPixmap(pix_platform_sp);
}
void platform_broken::reback() { plat->setPixmap(pix_platform); }
