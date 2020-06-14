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
    void horizon_intercial(bool direction);
    void doodle_test(); //x軸

    int ps_R;
    int ps_L;
    float doodle_pos_X;
    float doodle_pos_Y;
    void shot();
    static bool up_down;
    mainbullet _main;
    int Y_to_stay = 0;
    int t;
    int d = 0;
    int now_co;
    int here = 0;
    static int jump;
signals:
    void platform_move(int, int, int);
    //void to_stop_jump();
public slots:
    //void to_jump();

    //X - axis
    void move_L();
    void move_R();
    void ho_in();
    //bullet
    void aftershot();
    //Y - axis
    void timer_restart();
    bool collide_or_not();
    void jump_j();

protected:
    int type = 0;
    int time;
    int L_R;
    float t_t;
    float place_Y;

    float position;
    int push_time_R = 0;
    int push_time_L = 0;
    QGraphicsPixmapItem *player;
    QTimer *hor_int;
    QTimer *bullet_timer;
    QTimer *plt_mv_timer;
    QPixmap doodle_pix_type_1[3];
    QPixmap doodle_pix_type_2[3];
    QPixmap *bullet_type_1;
    QPixmap *bullet_type_2;
    bool up_or_down = true; //true is up
    bool collide_is_true = false;

public:
    int runtime; //in platform move
    int jump_way = 0;
    bool plt_mov = false;
    bool is_collided = false;
    int nonzero = 0;
    int do_time = 0;
    int k = 0;
    float count_vel = 0;
signals:
    void to_stop_end_signal();
    void main_window_signal(int);
    void mainwindow_start_time();
public slots:
    void move_platform_slot();
};

#endif // DOODLE_H
