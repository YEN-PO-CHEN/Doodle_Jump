#ifndef MONSTER4_H
#define MONSTER4_H
//left_right
#include "_basic.h"
#include "monster.h"
class monster4 : public monster
{
    Q_OBJECT
public:
    monster4(QGraphicsScene *);
    void pix_sel() override;
    void sle_x_y() override;
    void move_it() override;
    void add_sce() override;

protected:
    QPixmap pix_re;
    bool now = true;
};

#endif // MONSTER4_H
