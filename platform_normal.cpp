#include "platform_normal.h"

platform_normal::platform_normal(QGraphicsScene *scene, int X, int Y, int mm) : platform(scene, X, Y, mm) { add_pix(); }
void platform_normal::add_pix()
{
    pix_platform = QPixmap(":/rec/photo/platform/green/p-green.png");
    pix_platform = pix_platform.scaled(Platform_X_SIZE, Platform_Y_SIZE);
    set_x_y();
}
