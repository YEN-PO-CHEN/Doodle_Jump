#include "platform.h"

platform::platform(QGraphicsScene *I, int X, int Y) : _scene(I), X_plt(X), Y_plt(Y),_time_(new QTimer) {}
void platform::select_which_place()
{
    /*qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    X_plt = qrand() % (Scene_X - Platform_X_SIZE);
    Y_plt = qrand() % 30;
*/
}
platform::~platform() {}
