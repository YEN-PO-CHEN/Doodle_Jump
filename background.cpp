#include "background.h"

background::background(QGraphicsScene *mainwin, const int i) : back(new QGraphicsPixmapItem),
                                                               under(new QGraphicsPixmapItem),
                                                               type(i),
                                                               back_type_1(new QPixmap(":/rec/photo/background/scene1.jpg")),
                                                               back_type_2(new QPixmap(":/rec/photo/background/scene1.jpg")),
                                                               down(new QPixmap(":/rec/photo/topbar/topbar.png"))
{
    back->setPos(0, 0);
    if (type == 1)
        back->setPixmap(back_type_1->scaled(Scene_X, Scene_Y));
    if (type == 2)
        back->setPixmap(back_type_2->scaled(Scene_X, Scene_Y));
    under->setPos(0, DOODLE_HIGH + 10);
    under->setPixmap(down->scaled(Scene_X, 190));
    under->setZValue(200);
    back->setZValue(-100);
    //mainwin->addItem(under);
    mainwin->addItem(back);
}
