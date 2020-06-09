#ifndef DOODLE_H
#define DOODLE_H

#include <QObject>
#include <QWidget>
#include "_basic.h"

class doodle : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    doodle(QGraphicsScene *mainwin, int i);
    QGraphicsPixmapItem *player;
    QPixmap *doodle_pix;
    QTimer *jump_time;

public slots:
    void doodle_jump();
    void move_L();
    void move_R();

private:
    int type = 0;
    static int jump;
    double t_t;
    double place_Y;
    double doodle_pos_X;
    double doodle_pos_Y;
};

#endif // DOODLE_H
