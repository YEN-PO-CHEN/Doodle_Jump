#include "background.h"

background::background(QGraphicsScene *mainwin, const int i) : back(new QGraphicsPixmapItem),
                                                               type(i),
                                                               back_type_1(new QPixmap(":/rec/photo/background/scene1.jpg")),
                                                               back_type_2(new QPixmap(":/rec/photo/background/scene1.jpg"))
{
    back->setPos(0, 0);
    if (type == 1)
        back->setPixmap(back_type_1->scaled(Scene_X, Scene_Y));
    if (type == 2)
        back->setPixmap(back_type_2->scaled(Scene_X, Scene_Y));
    mainwin->addItem(back);
}
