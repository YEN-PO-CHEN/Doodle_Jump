#include "platform__build.h"

platform__build::platform__build(QGraphicsScene *I) : plt_Scene(I)
{
    v_platform.resize(Platform_NUM);
    reset_pltform();
    for (int mm = 0; mm < Platform_NUM; ++mm)
    {
        int a = place.at(mm).at(0);
        switch (a)
        {
        case 1:
        {
            mainbullet::pltfm_bool.at(mm) = 1;
            v_platform.at(mm) = new platform_broken(plt_Scene, place.at(mm).at(1), place.at(mm).at(2), mm);
            break;
        }
        case 2:
        {
            mainbullet::pltfm_bool.at(mm) = 2;
            v_platform.at(mm) = new platform_ver(plt_Scene, place.at(mm).at(1), place.at(mm).at(2), mm);
            break;
        }
        case 3:
        {
            mainbullet::pltfm_bool.at(mm) = 3;
            v_platform.at(mm) = new platform_hor(plt_Scene, place.at(mm).at(1), place.at(mm).at(2), mm);
            break;
        }
        case 0:
        {
            mainbullet::pltfm_bool.at(mm) = 0;
            v_platform.at(mm) = new platform_normal(plt_Scene, place.at(mm).at(1), place.at(mm).at(2), mm);
            break;
        }
        }
    }
}
void platform__build::reset_pltform()
{
    place.resize(Platform_NUM);
    for (int i = 0; i < Platform_NUM; ++i)
        place.at(i).resize(3, 0);
    place.at(0).at(0) = 0;
    place.at(0).at(1) = Default_X;
    place.at(0).at(2) = Default_Y + Doodle_SIZE;
    for (int i = 1; i < Platform_NUM; ++i)
    {
        int m = rand() % 100;
        if (m < 50)
            place.at(i).at(0) = 0;
        else if (m >= 50 && m < 60)
        {
            if (place.at(i - 1).at(0) == 1)
                place.at(i).at(0) = 0;
            else
                place.at(i).at(0) = 1;
        }
        else if (m >= 60 && m < 70)
            place.at(i).at(0) = 2;
        else
            place.at(i).at(0) = 3;
    }
    for (int i = 1; i < Platform_NUM; ++i)
    {
        int M = rand() % 200;
        int X = rand() % (Default_X - Platform_X_SIZE);
        M += 50;
        place.at(i).at(2) = place.at(i - 1).at(2) - M;
        place.at(i).at(1) = X;
    }
}
