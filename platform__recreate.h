#ifndef PLATFORM__RECREATE_H
#define PLATFORM__RECREATE_H

#include <QObject>
#include <QWidget>
#include "_basic.h"
#include "mainbullet.h"
#include "platform.h"
#include "platform_normal.h"
#include "platform_broken.h"
#include "platform_hor.h"
#include "platform_ver.h"
#include "platform__build.h"
class platform__recreate : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    platform__recreate(QGraphicsScene *);
    QGraphicsScene *_scene;
    void plt_recreate(int);
    void plt_count();
};

#endif // PLATFORM__RECREATE_H
