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
public slots:
    void move() override;

protected:
    int type = 0;
    QPixmap pix_platform;
    QTimer *ver_time;
    int plt_now_number;
};

#endif // PLATFORM_VER_H
