#ifndef PLATFORM_VER_H
#define PLATFORM_VER_H

#include <QObject>
#include <QWidget>
#include "platform.h"

class platform_ver : public platform
{
    Q_OBJECT
public:
    platform_ver();
    platform_ver(int, int);
    void put_into_the_scene(int);
    void add_pix();

protected:
    QPixmap pix_platform;
    int plt_now_number;
};

#endif // PLATFORM_VER_H
