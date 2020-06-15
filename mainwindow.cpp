#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow),
                                          scene(new QGraphicsScene(0, 0, Scene_X, Scene_Y)),
                                          view(new QGraphicsView(this)),
                                          timer(new QTimer(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    srand(time(NULL));
    //vector construct
    ctor_vector(); //ok

    //constructor
    bcgd = new background(scene, 1);
    dood = new doodle(scene, 1);
    _platform = new platform__build(scene);
    _platform_re = new platform__recreate(scene);

    //X-axis; KeyPressEvent;
    connect(this, SIGNAL(move_L_signal()), dood, SLOT(move_L())); //L
    connect(this, SIGNAL(move_R_signal()), dood, SLOT(move_R())); //R
    connect(this, SIGNAL(shot_W_signal()), this, SLOT(shooot())); //W
    //plat; auto-move; timer;
    timer->start(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(platform_is_moving()));
    //Y-axis; auto-move; timer;
    //connect(timer,SIGNAL(timeout()),this,SLOT(Y_jump()));
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
//doodle auto-jump
void MainWindow::Y_jump() //SLOT
{
    bool now;
    cout << "here";
    if (jump_time < 50)
        now = false;
    else
        now = true;
    if (jump_time <= 50)
        dood->jump_j(jump_time);
    if (jump_time > 50)
        dood->down_j(jump_time);
    if (dood->collide_or_not(now))
    {
        for (int m = 0; m < Platform_NUM; ++m)
            platform__build::v_platform.at(m)->change();
        jump_time = 0;
    }
    if (dood->player->y() < DOODLE_LOW)
        view->centerOn(Scene_X / 2, dood->player->y());
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
    if (k == 1) //300-599
        platform__build::v_platform.at(A)->setY(platform__build::v_platform.at(A)->y() - 1);
    if (k == 0) //0-299
        platform__build::v_platform.at(A)->setY(platform__build::v_platform.at(A)->y() + 1);
}
void MainWindow::hor(int A)
{
    ++Plt_vec_v.at(A);
    Plt_vec_v.at(A) = Plt_vec_v.at(A) % 600; //0-599
    int k = Plt_vec_v.at(A) / 300;
    if (k == 1) //300-599
        platform__build::v_platform.at(A)->setX(platform__build::v_platform.at(A)->x() - 1);
    if (k == 0) //0-299
        platform__build::v_platform.at(A)->setX(platform__build::v_platform.at(A)->x() + 1);
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
    platform__build::v_platform.resize(Platform_NUM);
}
MainWindow::~MainWindow() { delete ui; }
