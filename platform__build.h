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
                              { 0, Default_X, Default_Y+50},
                              { 0, Default_X, Default_Y+50},
                              { 0, Default_X, Default_Y+50},
                              { 0, Default_X, Default_Y+50},
                              { 0, Default_X, Default_Y+50},
                              { 0, Default_X, Default_Y+50},
                              { 0, Default_X, Default_Y+50},
                              { 0, Default_X, Default_Y+50},
                              { 0, Default_X, Default_Y+50},
                              { 0, Default_X, Default_Y+50},
                              { 0, Default_X, Default_Y+50}};


};

#endif // PLATFORM__BUILD_H
/*
 * vector<vector<int>> place{{ 0, Default_X, Default_Y+50},
                              { 1,       180,       550},
                              { 0,        30,       426},
                              { 3,       255,       394},
                              { 0,        11,       364},
                              { 0,       132,       329},
                              { 2,       354,       288},
                              { 0,       100,       200},
                              { 0,       280,       154},
                              { 2,       195,       102},
                              { 3,        40,        58},
                              { 0,       480,        20}};
*/
