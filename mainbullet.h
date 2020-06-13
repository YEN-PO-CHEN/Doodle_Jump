#ifndef MAINBULLET_H
#define MAINBULLET_H
#include "_basic.h"

class mainbullet : public QGraphicsPixmapItem
{
public:
    static vector<bool> bullet_of_number;
    static vector<int> pltfm_bool;
    static vector<QGraphicsPixmapItem *> pltfm_QItem;
};
#endif // MAINBULLET_H
