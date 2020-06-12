#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow),
                                          scene(new QGraphicsScene(0, 0, Scene_X, Scene_Y)),
                                          group(new QGraphicsItemGroup),
                                          timer(new QTimer(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    //constructor
    _main.pltfm_QItem.resize(Platform_NUM);
    _main.pltfm_bool.resize(Platform_NUM,true);
    bcgd = new background(scene, 1);
    dood = new doodle(scene, 1);

    _platform = new platform__build(scene);
    ctor_pltfm();
    bul.resize(Bullet_NUM);
    dood->connect(timer, SIGNAL(timeout()), dood, SLOT(doodle_jump()));
    dood->connect(this, SIGNAL(move_L_signal()), dood, SLOT(move_L()));
    dood->connect(this, SIGNAL(move_R_signal()), dood, SLOT(move_R()));
    timer->start(10);
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
