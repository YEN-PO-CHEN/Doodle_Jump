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
    timer->start(15);
    connect(timer, SIGNAL(timeout()), this, SLOT(platform_is_moving()));
    //Y-axis; auto-move; timer;
    connect(timer,SIGNAL(timeout()),this,SLOT(Y_jump()));
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
MainWindow::~MainWindow() { delete ui; }
//doodle auto-jump
void MainWindow::Y_jump() //SLOT
{
    if(dood->player->y() > (DOODLE_HIGH+DOODLE_LOW)/2||velocity>=0){
        dood->jump(velocity);
    }
    else{
        for(int now = 0;now<Platform_NUM;++now)
            _platform->v_platform.at(now)->jump(-velocity);
        //mon
        //str
    }

    if (collide(velocity))
        velocity = DOODLE_VEL;
    _platform_re->plt_count();
    velocity +=DOODLE_ACC;
}
bool MainWindow::collide(int now) //SLOT
{
    bool test = false;
    if (now<=0)
        return test;
    //down
    for (int tt = 0; tt < Platform_NUM; ++tt)
    {
        test = dood->player->collidesWithItem(platform__build::v_platform.at(tt)->plat, Qt::IntersectsItemBoundingRect);
        //qDebug() << "???";
        if (!test)
            continue;
        if (mainbullet::pltfm_bool.at(tt) == 1)
        {
            _platform->v_platform.at(tt)->change();
            _platform->v_platform.at(tt)->plat->setY(_platform->v_platform.at(tt)->plat->y() + Platform_Y_SIZE);
            _platform->v_platform.at(tt)->plat->setZValue(100);

            return false;
        }
        int YY = (_platform->v_platform.at(tt)->plat->y() - dood->player->y());
        int XX = (dood->player->x() - _platform->v_platform.at(tt)->plat->x());
        //0.5是可動參數
        if (YY < 0.6 * (Doodle_SIZE))
            test = false;
        if (XX > (Platform_X_SIZE) || XX < (-0.6) * (Doodle_SIZE))
            test = false;

        break;//is collide
    }
    return test;
}
