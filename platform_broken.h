#ifndef PLATFORM_BROKEN_H
#define PLATFORM_BROKEN_H

#include <QObject>
#include <QWidget>
#include "_basic.h"
#include "platform.h"
class platform_broken : public platform
{
    Q_OBJECT
public:
    platform_broken(QGraphicsScene *, QGraphicsItemGroup *);
    void put_into_the_scene();
};

#endif // PLATFORM_BROKEN_H
