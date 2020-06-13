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
                                  { 1,       0,       550},
                                  { 0,        0,       426},
                                  { 3,       0,       394},
                                  { 0,        0,       364},
                                  { 0,       0,       329},
                                  { 2,       0,       288},
                                  { 0,       0,       200},
                                  { 0,       0,       154},
                                  { 2,       0,       102},
                                  { 3,       0,        58},
                                  { 0, 0,        20}};


};
#endif // PLATFORM__BUILD_H
/*
 *
*/
