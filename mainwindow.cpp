#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow),
                                          scene(new QGraphicsScene(0, 0, Scene_X, Scene_Y)),
                                          group(new QGraphicsItemGroup),
                                          timer(new QTimer(this)),
                                          _timer(new QTimer(this)),
                                          start_moving_pla_timer(new QTimer)
{
    srand(time(NULL));
    vec_v.resize(Platform_NUM, 0);
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    //vector
    ctor_pltfm();
    bul.resize(Bullet_NUM);
    //constructor
    _platform_re = new platform__recreate(scene);
    bcgd = new background(scene, 1);
    dood = new doodle(scene, 1);
    _platform = new platform__build(scene);

    //X - axis
    connect(this, SIGNAL(move_L_signal()), dood, SLOT(move_L()));
    connect(this, SIGNAL(move_R_signal()), dood, SLOT(move_R()));

    connect(_timer, SIGNAL(timeout()), this, SLOT(platform_is_moving())); //平板移動
    connect(_platform_re, SIGNAL(restart()), this, SLOT(restart_timer()));
    timer->start(10);
    _timer->start(10);
    connect(timer, SIGNAL(timeout()), dood, SLOT(jump_j()));
    connect(dood, SIGNAL(main_window_signal(int)), this, SLOT(stop_timer(int)));
    connect(dood, SIGNAL(mainwindow_start_time()), this, SLOT(restart_timer()));

    //move plat
    connect(start_moving_pla_timer, SIGNAL(timeout()), this, SLOT(move_the_platform()));
    connect(this, SIGNAL(stop_this()), this, SLOT(restart_timer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

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
        shooot();
        break;
    }
}
void MainWindow::shooot()
{
    int count = 0;
    for (; count <= Bullet_NUM; ++count)
    {
        if (count == (Bullet_NUM))
            return;
        if (_main.bullet_of_number.at(count))
            break;
    }
    _main.bullet_of_number.at(count) = false;
    bul.at(count) = new bullet(scene, 1, dood->doodle_pos_X, dood->doodle_pos_Y, count);
    bul.at(count)->con();
}
void MainWindow::ctor_pltfm()
{
    _main.pltfm_bool.resize(Platform_NUM, true);
    _main.pltfm_QItem.resize(Platform_NUM);
}
void MainWindow::platform_is_moving()
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

    ++vec_v.at(A);
    vec_v.at(A) = vec_v.at(A) % 600; //0-599
    int k = vec_v.at(A) / 300;
    if (k == 1) //300-599
        _main.pltfm_QItem.at(A)->setY(_main.pltfm_QItem.at(A)->y() - 1);
    if (k == 0) //0-299
        _main.pltfm_QItem.at(A)->setY(_main.pltfm_QItem.at(A)->y() + 1);
}
void MainWindow::hor(int A)
{
    ++vec_v.at(A);
    vec_v.at(A) = vec_v.at(A) % 600; //0-599
    int k = vec_v.at(A) / 300;
    if (k == 1) //300-599
        _main.pltfm_QItem.at(A)->setX(_main.pltfm_QItem.at(A)->x() - 1);
    if (k == 0) //0-299
        _main.pltfm_QItem.at(A)->setX(_main.pltfm_QItem.at(A)->x() + 1);
}
void MainWindow::stop_timer(int A)
{
    PlatformTime = A;
    PlatformTime = 50;
    timer->stop();
    start_moving_pla_timer->start(10);
}
void MainWindow::restart_timer()
{
    PlatformTime = 50;
    timer->start(10);
    _timer->start(10);
    start_moving_pla_timer->stop();
}

void MainWindow::move_the_platform()
{
    cout << "in MainWindow move_the_platform" << endl;
    --PlatformTime;
    if (PlatformTime == 0)
        emit stop_this();
    float now = DOODLE_VEL + 0.5 * DOODLE_ACC - DOODLE_ACC * (50 - PlatformTime);
    for (int mmmm = 0; mmmm < Platform_NUM; ++mmmm)
        mainbullet::pltfm_QItem.at(mmmm)->setY(mainbullet::pltfm_QItem.at(mmmm)->y() + now);
}
