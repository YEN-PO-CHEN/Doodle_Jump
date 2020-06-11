#ifndef PLATFORM_VER_H
#define PLATFORM_VER_H

#include <QObject>
#include <QWidget>
#include "platform.h"

class platform_ver : public platform
{
    Q_OBJECT
public:
    platform_ver(QGraphicsScene *, QGraphicsItemGroup *);
    void put_into_the_scene();
};

#endif // PLATFORM_VER_H
