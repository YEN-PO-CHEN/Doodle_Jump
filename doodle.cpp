#include "doodle.h"

doodle::doodle(QGraphicsScene *mainwin, int i) : ps_R(0),
                                                 ps_L(0),
                                                 doodle_pos_X(Default_X),
                                                 doodle_pos_Y(Default_Y),
                                                 type(i),
                                                 L_R(0),
                                                 place_Y(Default_Y),
                                                 player(new QGraphicsPixmapItem),
                                                 hor_int(new QTimer),
                                                 plt_mv_timer(new QTimer),
                                                 doodle_pix_type_1{QPixmap(":/rec/photo/player/scene1/L.png"),
                                                                   QPixmap(":/rec/photo/player/scene1/R.png"),
                                                                   QPixmap(":/rec/photo/player/scene1/S.png")},
                                                 doodle_pix_type_2{QPixmap(":/rec/photo/player/scene1/L.png"),
                                                                   QPixmap(":/rec/photo/player/scene1/R.png"),
                                                                   QPixmap(":/rec/photo/player/scene1/S.png")}
{
    player->setPos(doodle_pos_X, doodle_pos_Y);
    for (int m = 0; m < 2; ++m)
    {
        doodle_pix_type_1[m] = doodle_pix_type_1[m].scaled(Doodle_SIZE, Doodle_SIZE);
        doodle_pix_type_2[m] = doodle_pix_type_2[m].scaled(Doodle_SIZE, Doodle_SIZE);
    }
    doodle_pix_type_1[2] = doodle_pix_type_1[2].scaled(Doodle_SIZE - 20, Doodle_SIZE + 20);
    doodle_pix_type_2[2] = doodle_pix_type_2[2].scaled(Doodle_SIZE - 20, Doodle_SIZE + 20);
    player->setPixmap(doodle_pix_type_1[0]);
    mainwin->addItem(player);
    connect(plt_mv_timer, SLOT(timeout()), this, SIGNAL(move_platform_slot()));
}
//Y
/**************************************************************************************
      ********************************Old
bool doodle::judge() //collide
{
    bool test = false;
    if (up_down) { return false; } //no collide
    //down
    for (int tt = 0; tt < Platform_NUM; ++tt)
    {
        test = player->collidesWithItem(_main.pltfm_QItem.at(tt),Qt::IntersectsItemBoundingRect);
        if (!test) continue;
        int YY = (_main.pltfm_QItem.at(tt)->y() - player->y());
        int XX = (player->x() - _main.pltfm_QItem.at(tt)->x());
        if (YY < 0.84 * (Doodle_SIZE))
            test = false;
        if (XX > (Platform_X_SIZE) || XX < (-0.8) * (Doodle_SIZE))
            test = false;
        if (test)
        {
            here = 1;
            Y_to_stay =_main.pltfm_QItem.at(tt)->y();
            now_co = tt;
            if(_main.pltfm_bool.at(tt) == 1){
                _main.pltfm_QItem.at(tt)->setPixmap(QPixmap(":/rec/photo/platform/brown/platform_brown_broken.png"));
                _main.pltfm_QItem.at(tt)->setY( _main.pltfm_QItem.at(tt)->y() + Platform_Y_SIZE);
                _main.pltfm_QItem.at(tt)->setZValue(1); }
            break;  
        } //is collide
    }
    return test;
}
***************************************************************************************************************************/
/*****************************************************************************************************************************Old
void doodle::to_jump() //Y
{ 
    if (judge())
        change();
    r_doodle_jump();
}
*****************************************************************************************************************************/
/*****************************************************************************************************************************Old
void doodle::change() //Y
{
    up_down = true;
    jump = 0;
}
*****************************************************************************************************************************/
/*****************************************************************************************************************************Old
bool doodle::check_place() //Y check
{
    if(jump<=50)
        upup();
    else
        lowlow();
}
*****************************************************************************************************************************/
/*****************************************************************************************************************************Old
void doodle::r_doodle_jump() { //revise Y jump
    jump++; //1-100
    check_place();
    player->setPos(doodle_pos_X, doodle_pos_Y);
    return;
}
*****************************************************************************************************************************/
/*****************************************************************************************************************************Old
void doodle::upup() { //Y up
    int t = 50 - jump;
    int now = doodle_pos_Y - (DOODLE_ACC / 2 )*(2*t + 1);

    //當y<200時
    if( now < DOODLE_LOW ){
        jump = 0;
        for(int iu = 0;iu<Platform_NUM;++iu)
            mainbullet::pltfm_QItem.at(iu)->setY(now);
    }
    else
        doodle_pos_Y = now;
    up_down = true;
    if(jump == 50){

    }

}
*****************************************************************************************************************************/
/*****************************************************************************************************************************Old
void doodle::lowlow() //Y down
{
    int t = jump - 50;
    int now = doodle_pos_Y + (DOODLE_ACC / 2 )*(2*t + 1);
    up_down = false; //down
    if(now > Scene_Y){
        //遊戲結束畫面

    }
    else
        doodle_pos_Y = now;
}*****************************************************************************************************************************/
//X
void doodle::move_R() //X
{
    ++push_time_R;
    player->setPixmap(doodle_pix_type_1[1]);
    doodle_test();
    doodle_pos_X += Move_By;
    horizon_intercial(false);
    doodle_test();
    player->setX(doodle_pos_X);
}
void doodle::move_L() //X
{
    ++push_time_L;
    player->setPixmap(doodle_pix_type_1[0]);
    doodle_test();
    doodle_pos_X -= Move_By;
    horizon_intercial(true);
    doodle_test();
    player->setX(doodle_pos_X);
}
void doodle::horizon_intercial(bool direction) //X
{
    if (direction)
        L_R = -1;
    else
        L_R = 1; //R
    time = 0;
    if (!hor_int)
    {
        delete hor_int;
        hor_int = new QTimer;
    }
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
    double vel = L_R * Doodle_horizonal_vel - (push_time_R - push_time_L) * Doodle_per_push * Doodle_vertical_acc;
    double acc = vel / Doodle_horizonal_run;
    position = vel - (acc / 2) * (2 * this->time + 1);
    doodle_pos_X += position;
    doodle_test();
}
void doodle::doodle_test() //X check
{
    if (doodle_pos_X >= Scene_X - Doodle_SIZE * 0.5)
    {
        doodle_pos_X -= (Scene_X);
        doodle_pos_X -= Doodle_SIZE / 2;
    }
    if (doodle_pos_X < Doodle_SIZE * -1 * 0.5)
    {
        doodle_pos_X += Scene_X;
        doodle_pos_X += Doodle_SIZE / 2;
    }
}
//shot
void doodle::shot()
{
    this->player->setPixmap(doodle_pix_type_1[2]);
    QTimer::singleShot(150, this, SLOT(aftershot()));
}
void doodle::aftershot() { player->setPixmap(doodle_pix_type_1[1]); }
void doodle::timer_restart()
{
    jump = 51;
    here = false;
}
void doodle::jump_j()
{
    bool up_is_true = true;
    jump %= 100;
    int t = jump + 1;
    float dy = 0;
    dy = DOODLE_VEL + 0.5 * DOODLE_ACC - DOODLE_ACC * t;
    if (dy < 0)
        up_is_true = true;
    else
        up_is_true = false;

    if (!up_is_true)
        if (!collide_is_true)
            collide_is_true = collide_or_not();

    if (collide_is_true)
        dy *= -1;
    float now = player->y() - dy;
    if (now < DOODLE_LOW)
        emit main_window_signal(jump);
    else
        player->setY(now);
    ++jump;
}
bool doodle::collide_or_not()
{
    bool test = false;
    if (up_down)
    {
        return false;
    } //no collide
    //down
    for (int tt = 0; tt < Platform_NUM; ++tt)
    {
        test = player->collidesWithItem(_main.pltfm_QItem.at(tt), Qt::IntersectsItemBoundingRect);
        if (!test)
            continue;
        int YY = (_main.pltfm_QItem.at(tt)->y() - player->y());
        int XX = (player->x() - _main.pltfm_QItem.at(tt)->x());
        //0.5是可動參數
        if (YY < 0.5 * (Doodle_SIZE))
            test = false;
        if (XX > (Platform_X_SIZE) || XX < (-0.8) * (Doodle_SIZE))
            test = false;
        if (test)
        {
            nonzero = 1;
            if (_main.pltfm_bool.at(tt) == 1)
            {
                _main.pltfm_QItem.at(tt)->setPixmap(QPixmap(":/rec/photo/platform/brown/platform_brown_broken.png"));
                _main.pltfm_QItem.at(tt)->setY(_main.pltfm_QItem.at(tt)->y() + Platform_Y_SIZE);
                _main.pltfm_QItem.at(tt)->setZValue(10);
            }
            break;
        } //is collide
    }
    return test;
}
void doodle::move_platform_slot()
{
    ++runtime;
    if (jump == 50)
    {
        cout << "RunTime =" << runtime << endl;
        plt_mv_timer->stop();
        emit mainwindow_start_time();
        return;
    }
    int tt = jump;
    int judge = 1;
    int now = judge * DOODLE_ACC * (2 * tt + 1);
    for (int mmmm = 0; mmmm < Platform_NUM; ++mmmm)
        mainbullet::pltfm_QItem.at(mmmm)->setY(mainbullet::pltfm_QItem.at(mmmm)->y() + now);
    jump++;
}
