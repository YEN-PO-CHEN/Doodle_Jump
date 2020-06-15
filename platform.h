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
    platform(QGraphicsScene *, int, int, int);
    void put_into_the_scene();
    void set_x_y();
    virtual void add_pix() = 0;
    virtual void to_move(int) {}
    virtual void change() {} //only broken
    virtual void reback() {} //only break
    virtual ~platform();
    void jump(double);
    QGraphicsPixmapItem *plat;

protected:
    QGraphicsScene *_scene;
    QPixmap pix_platform;
    int X_plt, Y_plt;
    int plt_now_number;
};

#endif // PLATFORM_H
