#ifndef PLATFORM__BUILD_H
#define PLATFORM__BUILD_H

#include <QObject>
#include <QWidget>
#include "_basic.h"
#include "platform.h"
#include "platform_normal.h"
#include "platform_broken.h"
#include "platform_hor.h"
#include "platform_ver.h"
class platform__build : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    platform__build(QGraphicsScene *);
    vector<platform* > v_platform;

private:
    QGraphicsScene *plt_Scene;
    vector<vector<int>> place{{0, Default_X, Default_Y},
                              { 1,      180,       550},
                              { 0,      160,        10},
                              { 3,      155,        60},
                              { 0,      149,       524},
                              { 0,      142,        37},
                              { 2,      124,       486},
                              { 0,      100,       300},
                              { 0,       80,        56},
                              { 2,       55,       546},
                              { 3,       40,       251},
                              { 0,       20,       300}};
};

#endif // PLATFORM__BUILD_H
