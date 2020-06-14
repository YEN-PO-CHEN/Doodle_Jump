#include "monster.h"

monster::monster(QGraphicsScene*I,int k):i(k),_scene(I)
{

}
void monster::add_t_scene(){
    mon = new QGraphicsPixmapItem;
    mon->setPos(X,Y);
    mon->setPixmap(pix_i);
    _scene->addItem(mon);
}

void monster::mon_delete(){
    if(be_shoot||mon->y() > Scene_Y)//true
    {
        this->_scene->removeItem(mon);
        delete this;
    }
}

void monster::set_x_y(){
}
