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
    dood = new doodle(scene, 1);
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
        dood->shot();
        shooot();

        break;
    }
}
void MainWindow::shooot()
{
    std::cout << "fuck" << std::endl;
    bul = new bullet(scene, 1, dood->doodle_pos_X, dood->doodle_pos_Y);
}
