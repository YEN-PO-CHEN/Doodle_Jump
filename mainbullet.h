#ifndef MAINBULLET_H
#define MAINBULLET_H
#include "_basic.h"
#include "platform.h"
class mainbullet : public QGraphicsPixmapItem
{
public:
    static vector<bool> bullet_of_number;
    static vector<int> pltfm_bool;
};
#endif // MAINBULLET_H
