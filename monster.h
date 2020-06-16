#ifndef MONSTER_H
#define MONSTER_H

#include <QObject>
#include <QWidget>
#include "_basic.h"
#include "platform__build.h"
class monster : public QObject, public QGraphicsPixmapItem, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    monster(QGraphicsScene *, int);
    virtual void pix_sel() = 0;
    virtual void sle_x_y() = 0;
    virtual void move_it() {}
    virtual void add_sce() = 0;
    void jump(double);
    void mon_delete();
    QGraphicsScene *_scene;
    QGraphicsPixmapItem *mon;
    QPixmap pix_i;
    int X, Y;

protected:
    int i;
};

#endif // MONSTER_H
