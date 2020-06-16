#ifndef MONSTER1_H
#define MONSTER1_H
//stop
#include <QObject>
#include <QWidget>
#include "monster.h"
class monster1 : public monster
{
    Q_OBJECT
public:
    monster1(QGraphicsScene *);
    void pix_sel() override;
    void sle_x_y() override;
    void add_sce() override;
};
#endif // MONSTER1_H
