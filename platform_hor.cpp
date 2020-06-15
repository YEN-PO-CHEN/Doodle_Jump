#include "platform_hor.h"
platform_hor::platform_hor(QGraphicsScene *scene, int X, int Y, int mm) : platform(scene, X, Y, mm) { add_pix(); }
void platform_hor::add_pix()
{
    pix_platform = QPixmap(":/rec/photo/platform/blue/platform-blue.png").scaled(Platform_X_SIZE, Platform_Y_SIZE);
    set_x_y();
}
