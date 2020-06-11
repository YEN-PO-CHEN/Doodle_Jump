#ifndef PLATFORM_H
#define PLATFORM_H
#include "_basic.h"
#include <QObject>
#include <QWidget>
#include "mainbullet.h"
class platform : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    platform(QGraphicsScene *noe);
    virtual ~platform();

protected:
    QGraphicsScene *here;
    int num_platform = Platform_NUM;
    mainbullet _pltfm;
};

#endif // PLATFORM_H
