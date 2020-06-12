#ifndef PLATFORM_NORMAL_H
#define PLATFORM_NORMAL_H

#include <QObject>
#include <QWidget>
#include "_basic.h"
#include "platform.h"
class platform_normal : public platform
{
    Q_OBJECT
public:
    platform_normal(QGraphicsScene *, int, int, int);
    void put_into_the_scene() override;
    void add_pix() override;
    void set_x_y() override;

protected:
    QPixmap pix_platform;
    int plt_now_number;
};

#endif // PLATFORM_NORMAL_H
