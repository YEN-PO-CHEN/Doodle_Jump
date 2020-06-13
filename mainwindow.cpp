#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow),
                                          scene(new QGraphicsScene(0, 0, Scene_X, Scene_Y)),
                                          group(new QGraphicsItemGroup),
                                          timer(new QTimer(this))
{
    vec_v.resize(Platform_NUM,0);
    srand(time(NULL));
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    //constructor
    _platform_re = new platform__recreate(scene);
    _main.pltfm_QItem.resize(Platform_NUM);
    _main.pltfm_bool.resize(Platform_NUM, true);
    bcgd = new background(scene, 1);
    dood = new doodle(scene, 1);
    _platform = new platform__build(scene);
    ctor_pltfm();
    bul.resize(Bullet_NUM);
    dood->connect(timer, SIGNAL(timeout()), dood, SLOT(to_jump()));
    connect(timer,SIGNAL(timeout()),this,SLOT(platform_is_moving()));
    dood->connect(this, SIGNAL(move_L_signal()), dood, SLOT(move_L()));
    dood->connect(this, SIGNAL(move_R_signal()), dood, SLOT(move_R()));
    connect(dood, SIGNAL(platform_move(int, int,int)), _platform_re, SLOT(move_the_platform(int, int,int)));
    _platform_re->connect(_platform_re->timer, SIGNAL(timeout()), _platform_re, SLOT(plat_move()));
    timer->start(10);
    platform_is_moving();
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

void MainWindow::platform_is_moving(){
    for(int A = 0 ; A<Platform_NUM;++A){
        if(_main.pltfm_bool.at(A) == 2)
           ;/* ver(A);*/
        else if(_main.pltfm_bool.at(A) == 3)
            hor(A);
    }
}

void MainWindow::ver(int A){

    ++vec_v.at(A);
    cout<<"fuck ";
    vec_v.at(A) = vec_v.at(A) % 600;//0-599
    int k = vec_v.at(A)/300;
    if(k == 1)//300-599
        _main.pltfm_QItem.at(A)->setY(_main.pltfm_QItem.at(A)->y()-0.2);
    if(k == 0)//0-299
        _main.pltfm_QItem.at(A)->setY(_main.pltfm_QItem.at(A)->y()+0.2);


}
void MainWindow::hor(int A){
    ++vec_v.at(A);
    cout<<"fuck ";
    vec_v.at(A) = vec_v.at(A) % 600;//0-599
    int k = vec_v.at(A)/300;
    if(k == 1)//300-599
        _main.pltfm_QItem.at(A)->setX(_main.pltfm_QItem.at(A)->x()-1);
    if(k == 0)//0-299
        _main.pltfm_QItem.at(A)->setX(_main.pltfm_QItem.at(A)->x()+1);
}
