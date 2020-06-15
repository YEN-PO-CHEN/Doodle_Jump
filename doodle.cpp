#include "doodle.h"
#include "mainwindow.h"
doodle::doodle(QGraphicsScene *mainwin, int i) :hor_int(new QTimer),
    plt_mv_timer(new QTimer),
    ps_R(0),
    ps_L(0),
    type(i-1),
    L_R(0),
    doodle_pix_type{{QPixmap(":/rec/photo/player/scene1/L.png").scaled(Doodle_SIZE, Doodle_SIZE),
                     QPixmap(":/rec/photo/player/scene1/R.png").scaled(Doodle_SIZE, Doodle_SIZE),
                     QPixmap(":/rec/photo/player/scene1/S.png").scaled(Doodle_SIZE - 20, Doodle_SIZE + 20)}
                   ,{QPixmap(":/rec/photo/player/scene1/L.png").scaled(Doodle_SIZE, Doodle_SIZE),
                     QPixmap(":/rec/photo/player/scene1/R.png").scaled(Doodle_SIZE, Doodle_SIZE),
                     QPixmap(":/rec/photo/player/scene1/S.png").scaled(Doodle_SIZE - 20, Doodle_SIZE + 20)}},
                     player(new QGraphicsPixmapItem)
{
    //Default Position
    player->setPos(Default_X, Default_Y);
    player->setPixmap(doodle_pix_type[type][0]);
    mainwin->addItem(player);
    connect(plt_mv_timer, SLOT(timeout()), this, SIGNAL(move_platform_slot()));
}
//X
void doodle::move_R() //X
{
    ++push_time_R;
    player->setPixmap(doodle_pix_type[type][1]);
    doodle_test();
    horizon_intercial(false);
    doodle_test();
    player->setX(player->x() + Move_By);
}
void doodle::move_L() //X
{
    ++push_time_L;
    player->setPixmap(doodle_pix_type[type][0]);
    doodle_test();
    horizon_intercial(true);
    doodle_test();
    player->setX(player->x() - Move_By);
}
void doodle::horizon_intercial(bool direction) //X
{
    if (direction)
        L_R = -1;
    else
        L_R = 1; //R
    time = 0;
    hor_int->stop();
    hor_int->start(10);
    connect(hor_int, SIGNAL(timeout()), this, SLOT(ho_in()));
}
void doodle::ho_in() //X inertia
{
    time++;
    if (time >= Doodle_horizonal_run)
    {
        delete hor_int;
        hor_int = new QTimer;
        time = 0;
        push_time_L = 0;
        push_time_R = 0;
        return;
    }
    position = 0;
    if (L_R == 1)
        --push_time_R;
    else
        --push_time_L;
    double vel = L_R * Doodle_horizonal_vel - (push_time_R - push_time_L) * Doodle_per_push * 0.5;
    double acc = vel / Doodle_horizonal_run;
    position = vel - (acc / 2) * (2 * this->time + 1);
    player->setX(player->x() + position);
    doodle_test();
}
void doodle::doodle_test() //X check
{
    if (player->x() >= Scene_X - Doodle_SIZE * 0.5)
    {
        player->setX(player->x() - (Scene_X));
        player->setX(player->x() - Doodle_SIZE / 2);
    }
    if (player->x() < Doodle_SIZE * -1 * 0.5)
    {
        player->setX(player->x() + (Scene_X));
        player->setX(player->x() + Doodle_SIZE / 2);
    }
}

//shot player change
void doodle::shot()
{
    player->setPixmap(doodle_pix_type[type][2]);
    QTimer::singleShot(150, this, SLOT(aftershot()));
}
void doodle::aftershot() { player->setPixmap(doodle_pix_type[type][1]); }
//
void doodle::timer_restart()
{
    jump = 51;
    here = false;
}
//y
void doodle::jump_j(int time)
{
    /**************************
     * time = 1 - 50 , t = 50 - 1
     **************************/
    float v_t_0 = DOODLE_VEL - DOODLE_ACC * (time - 1);
    float v_t_1 = DOODLE_VEL - DOODLE_ACC * time;
    float dy = (v_t_1 * v_t_1) - (v_t_0 * v_t_0);
    dy = dy * 0.5 / DOODLE_ACC;
    player->setY(player->y() - dy);
}
/*useless

    up_is_true = true;
    jump %= 100;
    int t = jump + 1;
    float dy = 0;
    dy = DOODLE_VEL + 0.5 * DOODLE_ACC - DOODLE_ACC * t;
    if (dy < 0)
        up_is_true = true;
    else
        up_is_true = false;
    collide_is_true = collide_or_not();
    if (nonzero == 1 ||collide_is_true)
        dy = DOODLE_VEL + 0.5 * DOODLE_ACC - DOODLE_ACC * (50-t);
    cout<<dy<<" "<<collide_is_true<<endl;
    float now = player->y() - dy;
    cout<<now<<"       nonzero         "<<nonzero<<endl;
    if (player->y() < DOODLE_LOW){
        nonzero = 0;
        emit main_window_signal(jump);
        player->setY(DOODLE_LOW+10);
    }else
        player->setY(now);

    ++jump;
    plt_count();
            */

void doodle::down_j(int time)
{
    /**************************
     * time 51 - 100 , t 1 - 50
     **************************/
    float v_t_0 = DOODLE_ACC * (time - 51);
    float v_t_1 = DOODLE_ACC * (time - 50);
    float dy = (v_t_1 * v_t_1) - (v_t_0 * v_t_0);
    dy = dy * 0.5 / DOODLE_ACC;
    player->setY(player->y() + dy);
}

int doodle::collide_or_not(bool now)
{
    if (now)
    {
        return 0;
    } //no collide
    //down
    for (int tt = 0; tt < Platform_NUM; ++tt)
    {
        bool test = player->collidesWithItem(platform__build::v_platform.at(tt)->plat, Qt::IntersectsItemBoundingRect);
        if (!test)
            continue;
        int YY = (platform__build::v_platform.at(tt)->plat->y() - player->y());
        int XX = (player->x() - platform__build::v_platform.at(tt)->plat->x());
        //0.5是可動參數
        if (YY < 0.8 * (Doodle_SIZE))
            test = false;
        if (XX > (Platform_X_SIZE) || XX < (-0.8) * (Doodle_SIZE))
            test = false;
        if (test)
        {
            nonzero = 1;
            if (mainbullet::pltfm_bool.at(tt) == 1)
            {
                platform__build::v_platform.at(tt)->change();
                platform__build::v_platform.at(tt)->plat->setY(platform__build::v_platform.at(tt)->plat->y() + Platform_Y_SIZE);
                platform__build::v_platform.at(tt)->plat->setZValue(100);
            }
            break;
        } //is collide
    }

    return nonzero;
}
void doodle::move_platform_slot()
{
    ++runtime;
    cout << jump << endl;
    if (jump == 50)
    {
        cout << "RunTime =" << runtime << endl;
        plt_mv_timer->stop();
        emit mainwindow_start_time();
        nonzero = 0;
        return;
    }
    int tt = jump;
    int judge = 1;
    int now = judge * DOODLE_ACC * (2 * tt + 1);
    for (int mmmm = 0; mmmm < Platform_NUM; ++mmmm)
        platform__build::v_platform.at(mmmm)->plat->setY(platform__build::v_platform.at(mmmm)->plat->y() + now);
    jump++;
    plt_count();
}
void doodle::plt_count()
{
    for (int plt_num = 0; plt_num < Platform_NUM; ++plt_num)
        if (platform__build::v_platform.at(plt_num)->plat->y() > (Scene_Y))
            plt_recreate(plt_num);
}
void doodle::plt_recreate(int I)
{
    int numX = rand() % (Scene_X - Platform_X_SIZE);
    int numY = rand() % 25;
    int dy = 0;
    for (int mm = 0; mm < Platform_NUM; ++mm)
        if (platform__build::v_platform.at(mm)->plat->y() < dy)
            dy = platform__build::v_platform.at(mm)->plat->y();
    numY = dy - numY - 150;
    platform__build::v_platform.at(I)->plat->setPos(numX, numY);
    platform__build::v_platform.at(I)->plat->setZValue(0);
    platform__build::v_platform.at(I)->reback();
}
