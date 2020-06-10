#ifndef PLATFORM_H
#define PLATFORM_H
#include "_basic.h"
#include <QObject>
#include <QWidget>

class platform : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    platform(QGraphicsScene *noe);
    ~platform();

protected:
    QGraphicsScene *here;
    vector<QGraphicsItem> *pltfm;
};

#endif // PLATFORM_H
