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

protected:
    QGraphicsPixmapItem *back;
    QGraphicsPixmapItem *under;
    int type;
    QPixmap *back_type_1;
    QPixmap *back_type_2;
    QPixmap *down;
};

#endif // BACKGROUND_H
