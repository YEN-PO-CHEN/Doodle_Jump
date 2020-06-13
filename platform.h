#ifndef PLATFORM_H
#define PLATFORM_H
#include "_basic.h"
#include <QObject>
#include <QWidget>
#include "mainbullet.h"

class platform : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    platform(QGraphicsScene *, int, int);
    virtual void put_into_the_scene() = 0;
    virtual void select_which_place();
    virtual void add_pix(){}
    virtual ~platform();
    virtual void set_x_y() = 0;

protected:
    QGraphicsScene *_scene;
    int num_platform = Platform_NUM;
    mainbullet _pltfm;
    int X_plt, Y_plt;
    int which_is_this;
    QTimer *_time_;

public slots:
    virtual void move() = 0;
};

#endif // PLATFORM_H
