#ifndef PLATFORM_BROKEN_H
#define PLATFORM_BROKEN_H

#include <QObject>
#include <QWidget>
#include "_basic.h"
#include "platform.h"

class platform_broken : public platform
{
    Q_OBJECT
public:
    platform_broken(QGraphicsScene *, int, int, int);
    void add_pix() override;
    void put_into_the_scene() override;
    void set_x_y() override;
public slots:
    void move() override{};

protected:
    QPixmap pix_platform[2];
    int plt_now_number;
};

#endif // PLATFORM_BROKEN_H
