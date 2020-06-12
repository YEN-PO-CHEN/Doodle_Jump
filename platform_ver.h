#ifndef PLATFORM_VER_H
#define PLATFORM_VER_H

#include <QObject>
#include <QWidget>
#include "platform.h"

class platform_ver : public platform
{
    Q_OBJECT
public:
    platform_ver(QGraphicsScene *, int, int, int);
    void put_into_the_scene() override;
    void add_pix() override;
    void set_x_y() override;

protected:
    QPixmap pix_platform;
    int plt_now_number;
};

#endif // PLATFORM_VER_H
