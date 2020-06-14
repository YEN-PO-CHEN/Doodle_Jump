#ifndef MONSTER4_H
#define MONSTER4_H

#include "_basic.h"
#include "monster.h"
class monster4 : public monster
{
    Q_OBJECT
public:
    monster4(QGraphicsScene *);

protected:
    QPixmap mn4;
};

#endif // MONSTER4_H
