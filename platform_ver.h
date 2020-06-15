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
    void add_pix() override;
    void to_move(int) override;
};

#endif // PLATFORM_VER_H
