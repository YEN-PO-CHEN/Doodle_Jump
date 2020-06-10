#ifndef PLATFORM_BLUE_H
#define PLATFORM_BLUE_H

#include <QObject>
#include <QWidget>
#include "_basic.h"
#include "platform.h"
class platform_blue : public platform
{
    Q_OBJECT
public:
    platform_blue(QGraphicsScene *mainscene);
};

#endif // PLATFORM_BLUE_H
