#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QWidget>
#include "_basic.h"
class bullet:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet(QGraphicsScene *mainwin, const int i,double X,double Y);

protected:
    double X_axis,Y_axis;
    QGraphicsPixmapItem *blt;
    int type;
    QPixmap *bullet_pix_type_1;
    QPixmap *bullet_pix_type_2;
    QTimer *blt_time;

public slots:
    void fly();
};

#endif // BULLET_H
