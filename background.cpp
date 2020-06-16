#include "background.h"

background::background(QGraphicsScene *mainwin, const int i) : back(new QGraphicsPixmapItem),
                                                               stop(new QGraphicsPixmapItem),
                                                               menu(new QGraphicsPixmapItem),
                                                               dead(new QGraphicsPixmapItem),
                                                               type(i),
                                                               back_type_1(new QPixmap(":/rec/photo/background/scene1.jpg")),
                                                               back_type_2(new QPixmap(":/rec/photo/background/scene1.jpg")),
                                                               down(new QPixmap(":/rec/photo/background/pause.png")),
                                                               menu_pix(new QPixmap(":/rec/photo/background/main_menu_bg.png")),
                                                               dead_pix(new QPixmap(":/rec/photo/background/dead_menu.jpg"))
{
    back->setPos(0, 0);
    if (type == 1)
        back->setPixmap(back_type_1->scaled(Scene_X, Scene_Y));
    if (type == 2)
        back->setPixmap(back_type_2->scaled(Scene_X, Scene_Y));
    stop->setPos(0, 0);
    stop->setPixmap(down->scaled(Scene_X, Scene_Y));
    stop->hide();
    menu->setPos(0, 0);
    menu->setPixmap(menu_pix->scaled(Scene_X, Scene_Y));
    menu->setZValue(5000);
    dead->setPos(0, 0);
    dead->setPixmap(dead_pix->scaled(Scene_X, Scene_Y));
    dead->setZValue(7000);
    dead->hide();
    mainwin->addItem(back);
    mainwin->addItem(stop);
    mainwin->addItem(menu);
}
