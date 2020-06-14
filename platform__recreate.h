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


class platform__recreate : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    platform__recreate(QGraphicsScene *);

    QGraphicsScene *_scene;
    QTimer *timer;
    mainbullet *_main;
    vector<platform *> v_platform;

    void plt_recreate(int);
    void plt_count();

public slots:
    void move_the_platform(int, int,int);
    void plat_move();
    void start_move();
signals:
    void resetitem(int);
    void restart();
protected:
    int length;
    int time_t;
    int time_s;
    double vel;
    int now_item;
    double a;
};

#endif // PLATFORM__RECREATE_H
