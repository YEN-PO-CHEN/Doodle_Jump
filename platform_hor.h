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
    platform_hor();
    void put_into_the_scene(int);

protected:
    QPixmap pix_platform;
    int plt_now_number;
};

#endif // PLATFORM_BLUE_H
