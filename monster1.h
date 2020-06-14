#ifndef MONSTER1_H
#define MONSTER1_H

#include <QObject>
#include <QWidget>
#include "monster.h"
class monster1 : public monster
{
    Q_OBJECT
public:
    monster1(QGraphicsScene *);

protected:
    QPixmap mn1;
};

#endif // MONSTER1_H
