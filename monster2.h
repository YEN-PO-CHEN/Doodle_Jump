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
    void pix_sel() override;
    void sle_x_y() override;
    void move_it() override;
    void add_sce() override;

protected:
    int now = 0;
};

#endif // MONSTER2_H
