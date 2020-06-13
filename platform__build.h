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
    vector<vector<int>> place{{ 0, Default_X, Default_Y+50},
                              { 1,        52,       550},
                              { 0,       100,       426},
                              { 3,       147,       394},
                              { 0,        13,       364},
                              { 0,        97,       329},
                              { 2,         7,       288},
                              { 0,       189,       200},
                              { 0,       164,       154},
                              { 2,       143,       102},
                              { 3,       200,        58},
                              { 0,       114,        20},
                              { 0,        65,       -80},//
                              { 1,        18,      -139},
                              { 2,        32,      -256},
                              { 0,       113,      -373},
                              { 0,        20,      -434},
                              { 0,       146,      -480},
                              { 1,       179,      -557},
                              { 0,        48,      -591},
                              { 0,       144,      -618},
                              { 3,        67,      -682},
                              { 2,       181,      -698},
                              { 0,        98,      -771}};


};
#endif // PLATFORM__BUILD_H
/*
 *
*/
