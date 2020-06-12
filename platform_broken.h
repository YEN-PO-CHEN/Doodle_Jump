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
    platform_broken();
    platform_broken(int ,int);
    void add_pix() override;
    void put_into_the_scene(int) override;
    void set_x_y() override;

protected:
    QPixmap pix_platform[2];
    int plt_now_number;
};

#endif // PLATFORM_BROKEN_H
