#include "platform.h"

platform::platform(QGraphicsScene *I, QGraphicsItemGroup *J) : _scene(I),
                                                               _itemGroup(J)
{
}
platform::platform(int X, int Y) : X_plt(X), Y_plt(Y) {}
platform::platform() {}
void platform::select_which_place()
{
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    X_plt = qrand() % (Scene_X - Platform_X_SIZE);
    Y_plt = qrand() & 30;
}
platform::~platform()
{
}
