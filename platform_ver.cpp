#include "platform_ver.h"

platform_ver::platform_ver(QGraphicsScene *scene, int X, int Y, int mm) : platform(scene, X, Y, mm) { add_pix(); }
void platform_ver::add_pix()
{
    pix_platform = QPixmap(":/rec/photo/platform/blue/p-dblue.png");
    pix_platform = pix_platform.scaled(Platform_X_SIZE, Platform_Y_SIZE);
    set_x_y();
}
