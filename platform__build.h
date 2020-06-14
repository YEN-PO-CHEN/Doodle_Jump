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
#include "mainbullet.h"
class platform__build : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    platform__build(QGraphicsScene *);
    mainbullet _main;
    vector<platform* > v_platform;
    void reset_pltform();

private:
    QGraphicsScene *plt_Scene;
    vector<vector<int>> place;


};
#endif // PLATFORM__BUILD_H
/*
 *
*/
