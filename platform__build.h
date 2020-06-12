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
    vector<vector<int>> place{{ 0, Default_X, Default_Y},
                              { 1,       180,       550},
                              { 0,        30,       426},
                              { 3,       155,       394},
                              { 0,        11,       364},
                              { 0,       132,       329},
                              { 2,        54,       288},
                              { 0,       100,       200},
                              { 0,        80,       154},
                              { 2,       105,       102},
                              { 3,        40,        58},
                              { 0,       120,        20}};
};

#endif // PLATFORM__BUILD_H
