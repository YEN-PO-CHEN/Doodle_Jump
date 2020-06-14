#ifndef MONSTER3_H
#define MONSTER3_H

#include "_basic.h"
#include "monster.h"
class monster3:public monster
{
    Q_OBJECT
public:
    monster3(QGraphicsScene*);

protected:
    QPixmap mn3;
};


#endif // MONSTER3_H
