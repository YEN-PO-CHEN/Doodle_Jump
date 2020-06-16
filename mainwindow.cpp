#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow),
                                          scene(new QGraphicsScene(0, 0, Scene_X, Scene_Y)),
                                          view(new QGraphicsView(this)),
                                          timer(new QTimer(this)),
                                          mon_timer(new QTimer(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    srand(time(NULL));
    //vector construct
    ctor_vector();      //ok
    ctor_tool_vector(); //ok
    //constructor
    bcgd = new background(scene, 1);
    dood = new doodle(scene, 1);
    _platform = new platform__build(scene);
    _platform_re = new platform__recreate(scene);
    ui->scoreLCD->display(0);
    ui->rstrt_Button->hide();
    bcgd->stop->hide();
    //X-axis; KeyPressEvent;
    connect(this, SIGNAL(move_L_signal()), dood, SLOT(move_L())); //L
    connect(this, SIGNAL(move_R_signal()), dood, SLOT(move_R())); //R
    connect(this, SIGNAL(shot_W_signal()), this, SLOT(shooot())); //W
    //plat; auto-move; timer;
    connect(timer, SIGNAL(timeout()), this, SLOT(platform_is_moving()));
    //Y-axis; auto-move; timer;
    connect(timer, SIGNAL(timeout()), this, SLOT(Y_jump()));
    connect(mon_timer, SIGNAL(timeout()), this, SLOT(mon_move()));
    //button
    connect(ui->pause_Button, SIGNAL(clicked()), this, SLOT(pause()));
    connect(ui->rstrt_Button, SIGNAL(clicked()), this, SLOT(resta()));
    connect(ui->start_Button, SIGNAL(clicked()), this, SLOT(resta()));
    //hazard
    hazard_pix = QPixmap(":/rec/photo/monsters/durka.png");
    hazard_item = new QGraphicsPixmapItem;
    hazard_item->setPos(0, (Scene_Y - Hazard_size));
    hazard_pix = hazard_pix.scaled(Hazard_size, Hazard_size);
    hazard_item->setPixmap(hazard_pix);
    scene->addItem(hazard_item);
    ui->pause_Button->hide();
    //menu
    bcgd->menu->show();
    ui->start_Button->show();
    ui->dead_LCD->hide();
    put_tool();
}
//Bullet ; keypressevent_W ; bullet.cpp
void MainWindow::shooot() //SLOT
{
    int count;
    for (count = 0; count <= Bullet_NUM; ++count)
    {
        if (count == (Bullet_NUM))
            return;
        if (_main.bullet_of_number.at(count))
            break;
    }
    _main.bullet_of_number.at(count) = false;
    bul.at(count) = new bullet(scene, 1, dood->player->x(), dood->player->y(), count);
}
void MainWindow::pause()
{
    pause_X = dood->player->x();
    pause_Y = dood->player->y();
    scene->removeItem(dood->player);
    timer->stop();
    mon_timer->stop();
    bcgd->stop->show();
    bcgd->stop->setZValue(10);
    ui->rstrt_Button->show();
    ui->pause_Button->hide();
}
void MainWindow::resta()
{
    ui->pause_Button->show();
    dood->player->setPos(pause_X, pause_Y);
    scene->addItem(dood->player);
    bcgd->menu->hide();
    bcgd->stop->hide();
    timer->start(15);
    mon_timer->start(15);
    ui->rstrt_Button->hide();
    ui->start_Button->hide();
}
void MainWindow::mon_move() //SLOT
{
    if (monster_is_alive)
        mon->move_it();
}
// plan auto-move
void MainWindow::platform_is_moving() //SLOT
{
    for (int A = 0; A < Platform_NUM; ++A)
    {
        if (_main.pltfm_bool.at(A) == 2)
            ver(A);
        else if (_main.pltfm_bool.at(A) == 3)
            hor(A);
    }
}
void MainWindow::ver(int A)
{
    ++Plt_vec_v.at(A);
    Plt_vec_v.at(A) = Plt_vec_v.at(A) % 600; //0-599
    int k = Plt_vec_v.at(A) / 300;
    _platform->v_platform.at(A)->to_move(k);
}
void MainWindow::hor(int A)
{
    ++Plt_vec_v.at(A);
    Plt_vec_v.at(A) = Plt_vec_v.at(A) % 600; //0-599
    int k = Plt_vec_v.at(A) / 300;
    _platform->v_platform.at(A)->to_move(k);
}
//Classic
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
    case Qt::Key_A:
    case Qt::Key_Left:
        dood->ps_L++;
        emit move_L_signal();
        break;
    case Qt::Key_D:
    case Qt::Key_Right:
        dood->ps_L++;
        emit move_R_signal();
        break;
    case Qt::Key_W:
    case Qt::Key_Up:
        dood->shot();
        emit shot_W_signal();
        break;
    }
}
void MainWindow::ctor_vector()
{
    Plt_vec_v.resize(Platform_NUM, 0);
    bul.resize(Bullet_NUM);
    _main.bullet_of_number.resize(Bullet_NUM, true);
    _main.pltfm_bool.resize(Platform_NUM, 0);
}
void MainWindow::create_the_monster()
{
    int k = rand() % 4;
    if (monster_is_alive)
        return;

    switch (k)
    {
    case 0:
    {
        mon = new monster1(scene);
        break;
    }
    case 1:
    {

        mon = new monster2(scene);
        break;
    }
    case 2:
    {

        mon = new monster3(scene);
        break;
    }
    case 3:
    {

        mon = new monster4(scene);
        break;
    }
    }
    mon->mon->setPos(mon->X, mon->Y);
    mon->mon->setPixmap(mon->pix_i);
    scene->addItem(mon->mon);
    monster_is_alive = true;
    mon_timer->start(15);
}
void MainWindow::deadth()
{
    ui->pause_Button->hide();
    ui->scoreLCD->hide();

    ui->dead_LCD->display(show_on_lcd);
    velocity = DOODLE_VEL;
    mon_timer->start(10);
    connect(mon_timer, SIGNAL(timeout()), this, SLOT(doodle_death()));
    timer->stop();
    QTimer::singleShot(500, this, SLOT(afterdeath()));
}
void MainWindow::ctor_tool_vector()
{
    tool_string_pix.resize(2);
    tool_string.resize(2);
    tool_rocket_pix.resize(3);
    tool_rocket_pix.at(0) = QPixmap(":/rec/photo/bonus/rocket/raketa_on_panel.png").scaled(26, 38);
    tool_rocket_pix.at(1) = QPixmap(":/rec/photo/bonus/rocket/raketa_2left.png").scaled(10, 23);
    tool_rocket_pix.at(2) = QPixmap(":/rec/photo/bonus/rocket/raketa_3right.png").scaled(10, 23);

    tool_string_pix.at(0) = QPixmap(":/rec/photo/bonus/string/pruz1.png").scaled(18, 14);
    tool_string_pix.at(1) = QPixmap(":/rec/photo/bonus/string/pruz2.png").scaled(18, 28);
    for (int i = 0; i < 3; ++i)
    {
        if (i < 2)
            tool_string.at(i) = new QGraphicsPixmapItem;
        else
            tool_rocket = new QGraphicsPixmapItem;
    }
}
void MainWindow::put_tool()
{
    int a = 0;
    while (a != 4)
    {
        int m = (rand() % 23);
        m += 1;
        if (mainbullet::pltfm_bool.at(m) == 0)
        {
            double X = _platform->v_platform.at(m)->plat->x();
            double Y = _platform->v_platform.at(m)->plat->y();
            if (a < 2)
            {
                tool_string.at(a)->setPixmap(tool_string_pix.at(0));
                tool_string.at(a)->setPos(X, Y - 18);
                scene->addItem(tool_string.at(a));
            }
            else
            {
                tool_rocket->setPixmap(tool_rocket_pix.at(0));
                tool_rocket->setPos(X + 0.5 * Platform_X_SIZE, Y - 40);
                scene->addItem(tool_rocket);
            }
            ++a;
        }
    }
}
void MainWindow::doodle_death()
{
    dood->player->setY(dood->player->y() + 20);
}

void MainWindow::return_to_orignal()
{
    shield_or_not = false;
    rocket_or_not = false;
}
void MainWindow::afterdeath() //SLOT
{
    ui->dead_LCD->show();
    scene->removeItem(dood->player);
    QGraphicsPixmapItem *death_background = new QGraphicsPixmapItem;
    death_background->setPixmap(QPixmap(":/rec/photo/background/dead_menu.jpg").scaled(400, 800));
    scene->addItem(death_background);
    mon_timer->stop();
}
MainWindow::~MainWindow() { delete ui; }
//doodle auto-jump
void MainWindow::Y_jump() //SLOT
{
    bool mon_bul = false;
    //dead
    if (dood->player->y() > Scene_Y)
        deadth();
    if (dood->player->y() > 300 || velocity >= 0)
        dood->jump(velocity);
    else
    {
        show_on_lcd -= velocity;
        ui->scoreLCD->display(show_on_lcd);
        for (int now = 0; now < Platform_NUM; ++now)
            _platform->v_platform.at(now)->jump(-velocity);
        tool_rocket->setY(tool_rocket->y() - velocity);
        tool_string.at(0)->setY(tool_string.at(0)->y() - velocity);
        tool_string.at(1)->setY(tool_string.at(1)->y() - velocity);
        hazard_item->setY(hazard_item->y() - velocity);
        if (monster_is_alive)
        {
            mon->jump(-velocity);
            if (mon->mon->y() > Scene_Y)
            {
                mon_bul = true;
            }
        }
    }
    if (collide(velocity))
        velocity = DOODLE_VEL;

    int i;
    for (i = 0; i < Bullet_NUM; ++i)
    {
        if (_main.bullet_of_number.at(i))
            continue;
        if (monster_is_alive && mon->mon->collidesWithItem(bul.at(i)->blt, Qt::IntersectsItemBoundingRect))
        {
            mon_bul = true;
        }
    }
    if (mon_bul)
    {
        mon->mon_delete();
        mon_timer->stop();
        for (i = 0; i < Bullet_NUM; ++i)
        {
            if (_main.bullet_of_number.at(i))
                continue;
            else
                bul.at(i)->remove();
        }
        monster_is_alive = false;
    }
    if (((show_on_lcd / 1000) - _5000_cycle) > 0)
    {
        _5000_cycle += 1;
        create_the_monster();
    }
    if (hazard_item->y() > Scene_Y)
    {
        double hazard_X, hazard_Y;
        int here, dy = 0;
        for (int m = 0; m < Platform_NUM; ++m)
        {
            if (_platform->v_platform.at(m)->plat->y() < dy)
            {
                dy = _platform->v_platform.at(m)->plat->y();
                here = m;
            }
        }
        hazard_X = _platform->v_platform.at(here)->plat->x() + 100;
        if (hazard_X > Scene_X)
            hazard_X = hazard_X - Scene_X;
        hazard_Y = _platform->v_platform.at(here)->plat->y() - Hazard_size;
        hazard_item->setPos(hazard_X, hazard_Y);
    }
    //String
    for (int i = 0; i < 2; i++)
    {
        if (tool_string.at(i)->y() > Scene_Y)
        {
            double String_X, String_Y;
            int here, dy = 0;
            for (int m = 0; m < Platform_NUM; ++m)
            {
                if (_main.pltfm_bool.at(m) != 0)
                    continue;
                if (_platform->v_platform.at(m)->plat->y() < dy)
                {
                    dy = _platform->v_platform.at(m)->plat->y();
                    here = m;
                }
            }
            tool_string.at(i)->setPixmap(tool_string_pix.at(0));
            String_X = _platform->v_platform.at(here)->plat->x();
            String_Y = _platform->v_platform.at(here)->plat->y() - 14;
            tool_string.at(i)->setPos(String_X, String_Y);
        }
    }
    //rocket
    if (tool_rocket->y() > Scene_Y)
    {
        tool_rocket->show();
        tool_rocket->setZValue(0);
        double Rocket_X, Rocket_Y;
        int here, dy = 0;
        for (int m = 0; m < Platform_NUM; ++m)
        {
            if (_main.pltfm_bool.at(m) != 0)
                continue;
            if (_platform->v_platform.at(m)->plat->y() < dy)
            {
                dy = _platform->v_platform.at(m)->plat->y();
                here = m;
            }
        }
        tool_rocket->setPixmap(tool_string_pix.at(0));
        Rocket_X = _platform->v_platform.at(here)->plat->x();
        Rocket_Y = _platform->v_platform.at(here)->plat->y() - 14;
        tool_rocket->setPos(Rocket_X, Rocket_Y);
    }
    _platform_re->plt_count();
    velocity += DOODLE_ACC;
}
bool MainWindow::collide(int now) //SLOT
{
    bool test = false;
    if (rocket_or_not)
        return test;
    //rocket
    if (dood->player->collidesWithItem(tool_rocket, Qt::IntersectsItemBoundingRect))
    {
        rocket_or_not = true;
        tool_rocket->setZValue(-100);
        QTimer::singleShot(3000, this, SLOT(return_to_orignal()));
        if (velocity <= 0)
            velocity = velocity + 3 * DOODLE_VEL;
        else
            velocity = (-1) * velocity + 3 * DOODLE_VEL;
    }

    if (dood->player->collidesWithItem(hazard_item, Qt::IntersectsItemBoundingRect))
        deadth();
    if (monster_is_alive)
    {
        if (dood->player->collidesWithItem(mon->mon, Qt::IntersectsItemBoundingRect))
            deadth();
    }

    if (now <= 0)
        return test;
    //string
    for (int i = 0; i < 2; ++i)
        if (dood->player->collidesWithItem(tool_string.at(i), Qt::IntersectsItemBoundingRect))
        {
            tool_string.at(i)->setY(tool_string.at(i)->y() - 14);
            tool_string.at(i)->setPixmap(tool_string_pix.at(1));
            velocity = -velocity + 1.5 * DOODLE_VEL;
        }
    //down
    for (int tt = 0; tt < Platform_NUM; ++tt)
    {
        test = dood->player->collidesWithItem(platform__build::v_platform.at(tt)->plat, Qt::IntersectsItemBoundingRect);

        if (!test)
            continue;
        if (mainbullet::pltfm_bool.at(tt) == 1)
        {
            _platform->v_platform.at(tt)->change();
            _platform->v_platform.at(tt)->plat->setY(_platform->v_platform.at(tt)->plat->y() + Platform_Y_SIZE);
            return false;
        }
        int YY = (_platform->v_platform.at(tt)->plat->y() - dood->player->y());
        int XX = (dood->player->x() - _platform->v_platform.at(tt)->plat->x());
        //0.5是可動參數
        if (YY < 0.6 * (Doodle_SIZE))
            test = false;
        if (XX > (Platform_X_SIZE) || XX < (-0.6) * (Doodle_SIZE))
            test = false;
        break; //is collide
    }
    return test;
}
