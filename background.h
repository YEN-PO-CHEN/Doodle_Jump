#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QObject>
#include <QWidget>
#include "_basic.h"
class background : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    background(QGraphicsScene *mainwin, const int i);
    QGraphicsPixmapItem *back;
    QGraphicsPixmapItem *stop;
    QGraphicsPixmapItem *menu;
    QGraphicsPixmapItem *dead;

protected:
    int type;
    QPixmap *back_type_1;
    QPixmap *back_type_2;
    QPixmap *down;
    QPixmap *menu_pix;
    QPixmap *dead_pix;
};

#endif // BACKGROUND_H
