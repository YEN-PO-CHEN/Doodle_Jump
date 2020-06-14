#ifndef MONSTER_H
#define MONSTER_H

#include <QObject>
#include <QWidget>
#include "_basic.h"
class monster : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    monster(QGraphicsScene *, int);
    void add_t_scene();
    void mon_delete();
    bool be_shoot = false;
    void set_x_y();

protected:
    int i;
    QGraphicsScene *_scene;
    QGraphicsPixmapItem *mon;
    QPixmap pix_i;
    int X = 0, Y = 0;
};

#endif // MONSTER_H
