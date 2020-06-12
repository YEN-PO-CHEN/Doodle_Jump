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
    platform();
    platform(QGraphicsScene *);
    platform(int, int);
    virtual void put_into_the_scene(int){};
    virtual void select_which_place();
    virtual void add_pix(){};
    virtual ~platform();
    virtual void set_x_y() = 0;

protected:
    QGraphicsScene *_scene;
    int num_platform = Platform_NUM;
    mainbullet _pltfm;
    int X_plt, Y_plt;
};

#endif // PLATFORM_H
