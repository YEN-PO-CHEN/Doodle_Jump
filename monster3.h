#ifndef MONSTER3_H
#define MONSTER3_H

#include "_basic.h"
#include "monster.h"
class monster3 : public monster
{
    Q_OBJECT
public:
    monster3(QGraphicsScene *);
    void pix_sel() override;
    void sle_x_y() override;
    void move_it() override;
    void add_sce() override;
};

#endif // MONSTER3_H
