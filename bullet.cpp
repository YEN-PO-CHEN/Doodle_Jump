#include "bullet.h"

bullet::bullet(QGraphicsScene *mainwin, const int i, const float X, const float Y, const int count) : 
    blt(new QGraphicsPixmapItem),
    X_axis(X + Doodle_SIZE / 2 - 20),
    Y_axis(Y),
    type(i),
    which_bul(count),
    bullet_pix_type_1(new QPixmap(":/rec/photo/bullet/brown.png")),
    bullet_pix_type_2(new QPixmap(":/rec/photo/bullet/blue.png")),
    blt_time(new QTimer),
    here(mainwin)
{
    blt->setPos(X_axis, Y_axis);
    if (type == 1)
        blt->setPixmap(bullet_pix_type_1->scaled(Doodle_SIZE / 3, Doodle_SIZE / 3));
    if (type == 2)
        blt->setPixmap(bullet_pix_type_2->scaled(Doodle_SIZE / 3, Doodle_SIZE / 3));
    mainwin->addItem(blt);
    connect(this, SIGNAL(rem_bul()), this, SLOT(remove()));
    connect(blt_time, SIGNAL(timeout()), this, SLOT(fly()));
    blt_time->start(5);
}

void bullet::fly() //SLOT
{
    Y_axis -= 7;
    blt->setPos(X_axis, Y_axis - 20);
    if (Y_axis < 20)
        emit rem_bul();
}
void bullet::remove() //SLOT
{
    this->here->removeItem(blt);
    disconnect(blt_time, SIGNAL(timeout()), this, SLOT(fly()));
    disconnect(this, SIGNAL(rem_bul()), this, SLOT(remove()));
    blt_time->stop();
    mainbullet::bullet_of_number.at(which_bul) = true;
    delete this;
}
