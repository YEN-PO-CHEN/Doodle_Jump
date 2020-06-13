#ifndef PLATFORM__RECREATE_H
#define PLATFORM__RECREATE_H

#include <QObject>
#include <QWidget>
#include "_basic.h"
#include "mainbullet.h"

class platform__recreate : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    platform__recreate(QGraphicsScene *);

    QGraphicsScene *_scene;
    QTimer *timer;
    mainbullet *_main;
public slots:
    void move_the_platform(int, int);
    void plat_move();

protected:
    int length;
    int time_t;
    double vel;
};

#endif // PLATFORM__RECREATE_H
