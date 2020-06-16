#include "monster.h"

monster::monster(QGraphicsScene *I, int k) : _scene(I), i(k) { mon = new QGraphicsPixmapItem; }

void monster::mon_delete()
{
    this->_scene->removeItem(mon);
    delete this;
}
void monster::jump(double I) { mon->setY(mon->y() + I); }
