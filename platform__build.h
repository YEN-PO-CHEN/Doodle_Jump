#ifndef PLATFORM__BUILD_H
#define PLATFORM__BUILD_H

#include <QObject>
#include <QWidget>
#include "_basic.h"
#include "platform.h"
#include "platform_normal.h"
#include "platform_broken.h"
#include "platform_hor.h"
#include "platform_ver.h"
class platform__build : public QObject, public QGraphicsPixmapItem, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    platform__build(QGraphicsScene *, QGraphicsItemGroup *);

private:
    QGraphicsScene *plt_Scene;
    QGraphicsItemGroup *plt_Group;
};

#endif // PLATFORM__BUILD_H
