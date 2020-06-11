#ifndef PLATFORM_H
#define PLATFORM_H
#include "_basic.h"
#include <QObject>
#include <QWidget>
#include "mainbullet.h"
class platform : public QObject, public QGraphicsPixmapItem, public QGraphicsItemGroup
{
    Q_OBJECT
public:
    platform(QGraphicsScene *, QGraphicsItemGroup *);
    virtual void put_into_the_scene() {}
    virtual ~platform();

protected:
    QGraphicsScene *_scene;
    QGraphicsItemGroup *_itemGroup;
    int num_platform = Platform_NUM;
    mainbullet _pltfm;
};

#endif // PLATFORM_H
