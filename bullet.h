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
    void con();
    mainbullet main_bul;

protected:
    float X_axis, Y_axis;
    int type;
    QPixmap *bullet_pix_type_1;
    QPixmap *bullet_pix_type_2;
    QTimer *blt_time;
    QGraphicsScene *here;
    int which_bul;

public slots:
    void fly();
signals:
    void bomb(int);
};

#endif // BULLET_H
