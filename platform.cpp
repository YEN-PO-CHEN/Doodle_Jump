#include "platform.h"

platform::platform(QGraphicsScene *I, int X, int Y, int mm) : plt_now_number(mm), _scene(I), X_plt(X), Y_plt(Y) {}
platform::~platform() {}

void platform::jump(double I) { plat->setY(plat->y() + I); }
void platform::set_x_y()
{
    plat = new QGraphicsPixmapItem;
    put_into_the_scene();
}
void platform::put_into_the_scene()
{
    plat->setPos(X_plt, Y_plt);
    plat->setPixmap(pix_platform);
    _scene->addItem(plat);
}
