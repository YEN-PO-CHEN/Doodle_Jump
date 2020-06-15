#ifndef DOODLE_H
#define DOODLE_H

#include <QObject>
#include <QWidget>
#include "_basic.h"
#include "mainbullet.h"
class doodle : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    doodle(QGraphicsScene *mainwin, int i);
    mainbullet _main;
    QTimer *hor_int;
    QGraphicsPixmapItem *player;
    void horizon_intercial(bool direction);
    void doodle_test();
    void shot();
    void jump(double);
    int nonzero = 0;//collide_or_not
    int ps_R;
    int ps_L;
private:
    QPixmap doodle_pix_type[2][3];
    int type = 0;
    int L_R;
    int time;//ho_in
    int push_time_R = 0;//move_L
    int push_time_L = 0;//move_R
    float position;//ho_in
public slots:
    //X - axis
    void move_L();
    void move_R();
    void ho_in();
    void aftershot();//bullet
};

#endif // DOODLE_H
