#include "bullet.h"

bullet::bullet(QGraphicsScene *mainwin, const int i, const float X, const float Y, const int count) : blt(new QGraphicsPixmapItem),
                                                                                                      X_axis(X + Doodle_SIZE / 2 - 20),
                                                                                                      Y_axis(Y),
                                                                                                      type(i),
                                                                                                      bullet_pix_type_1(new QPixmap(":/rec/photo/bullet/brown.png")),
                                                                                                      bullet_pix_type_2(new QPixmap(":/rec/photo/bullet/blue.png")),
                                                                                                      blt_time(new QTimer),
                                                                                                      here(mainwin),
                                                                                                      which_bul(count)
{
    blt->setPos(X_axis, Y_axis);
    if (type == 1)
        blt->setPixmap(bullet_pix_type_1->scaled(Doodle_SIZE / 3, Doodle_SIZE / 3));
    if (type == 2)
        blt->setPixmap(bullet_pix_type_2->scaled(Doodle_SIZE / 3, Doodle_SIZE / 3));

    mainwin->addItem(blt);
}

void bullet::fly()
{
    Y_axis -= 7;
    blt->setPos(X_axis, Y_axis - 30);
    if (Y_axis < 20)
    {
        this->here->removeItem(blt);
        main_bul.bullet_of_number.at(which_bul) = true;
        delete this;
    }
}

void bullet::con()
{
    if (!blt_time)
        delete blt_time;
    blt_time = new QTimer;
    connect(blt_time, SIGNAL(timeout()), this, SLOT(fly()));
    blt_time->start(5);
}
