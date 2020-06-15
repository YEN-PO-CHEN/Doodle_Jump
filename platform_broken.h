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
    void change() override;
    void reback() override;

protected:
    QPixmap pix_platform_sp;
};

#endif // PLATFORM_BROKEN_H
