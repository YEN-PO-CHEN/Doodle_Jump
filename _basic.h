#ifndef _BASIC_H
#define _BASIC_H

//headerfile

#include <QGraphicsScene>

#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsItemGroup>
#include <QKeyEvent>
#include <QTimer>
#include <iostream>
#include <QVector>
using namespace std;

//define

#define bigger_sqrt 1.414
#define Scene_X 400
#define Scene_Y 800
#define Default_X 200
#define Default_Y 600


/******************
 * DOODLE
******************/
#define Doodle_SIZE 80

//doodle jump time

//double
#define Doodle_Jump_time 100.0
//int
#define Doodle_Jump_time_int 100

// 2/sqrt(Doodle_Jump_time_int/100)/10
#define Doodle_vertical_acc 0.16329 * 1.3 * 1.4

#define Doodle_horizonal_acc 0.02
#define Doodle_horizonal_run 100
#define Doodle_horizonal_vel (Doodle_horizonal_acc * Doodle_horizonal_run)
#define Doodle_per_push 0.01
#define Move_By 10


/******************
 * BULLET
******************/
#define Bullet_NUM 5


/******************
 * PLATFORM
******************/

#define Platform_NUM 12

#endif // _BASIC_H
