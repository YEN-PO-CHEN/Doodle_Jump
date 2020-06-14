#ifndef MONSTER2_H
#define MONSTER2_H

#include <QObject>
#include <QWidget>
#include "_basic.h"
#include "monster.h"
class monster2 : public monster
{
    Q_OBJECT
public:
    monster2(QGraphicsScene *);

protected:
    QPixmap mn2;
};

#endif // MONSTER2_H
