#ifndef PLATFORM_NORMAL_H
#define PLATFORM_NORMAL_H

#include <QObject>
#include <QWidget>
#include "_basic.h"
#include "platform.h"
class platform_normal : public platform
{
    Q_OBJECT
public:
    platform_normal(QGraphicsScene *, QGraphicsItemGroup *);
    void put_into_the_scene();
};

#endif // PLATFORM_NORMAL_H
