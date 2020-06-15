#ifndef PLATFORM_HOR_H
#define PLATFORM_HOR_H

#include <QObject>
#include <QWidget>
#include "_basic.h"
#include "platform.h"

class platform_hor : public platform
{
    Q_OBJECT
public:
    platform_hor(QGraphicsScene *, int, int, int);
    void add_pix() override;
    void to_move(int) override;
};

#endif // PLATFORM_BLUE_H
