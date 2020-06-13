#include "platform__build.h"

platform__build::platform__build(QGraphicsScene *I) : plt_Scene(I)
{
    v_platform.resize(Platform_NUM);
    for (int mm = 0; mm < Platform_NUM; ++mm)
    {
        int a = place.at(mm).at(0);

        switch (a)
        {
        case 1:
        {
            platform_broken pla_a(plt_Scene, place.at(mm).at(1), place.at(mm).at(2), mm);
            v_platform.at(mm) = &pla_a;
            break;
        }
        case 2:
        {
            platform_ver pla_b(plt_Scene, place.at(mm).at(1), place.at(mm).at(2), mm);
            v_platform.at(mm) = &pla_b;
            break;
        }
        case 3:
        {
            platform_hor pla_c(plt_Scene, place.at(mm).at(1), place.at(mm).at(2), mm);
            v_platform.at(mm) = &pla_c;
            break;
        }
        case 0:
        {
            platform_normal pla_d(plt_Scene, place.at(mm).at(1), place.at(mm).at(2), mm);
            v_platform.at(mm) = &pla_d;
            break;
        }
        }
    }
}
