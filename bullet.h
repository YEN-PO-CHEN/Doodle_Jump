#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QWidget>
#include "_basic.h"
#include "mainbullet.h"
class bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet(QGraphicsScene *mainwin, const int i, float X, float Y, int count);
    QGraphicsPixmapItem *blt;

protected:
    float X_axis, Y_axis;
    int type;
    int which_bul;
    QPixmap *bullet_pix_type_1;
    QPixmap *bullet_pix_type_2;
    QTimer *blt_time;
    QGraphicsScene *here;


public slots:
    void fly();
    void remove();
signals:
    void bomb(int);
    void rem_bul();
};

#endif // BULLET_H
