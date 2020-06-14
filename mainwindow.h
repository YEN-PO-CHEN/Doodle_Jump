#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "_basic.h"
#include "bullet.h"
#include "doodle.h"
#include "background.h"
#include "mainbullet.h"
#include "platform.h"
#include "platform__build.h"
#include "platform__recreate.h"
namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *e);
    void shooot();
    mainbullet _main;
    void ctor_pltfm();

    void ver(int);
    void hor(int);
    vector<int> vec_v;

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *pic;
    QGraphicsTextItem *text;
    QGraphicsItemGroup *group;
    QTimer *timer;
    QTimer *_timer;
    QTimer *start_moving_pla_timer;
    doodle *dood;
    vector<bullet *> bul;
    background *bcgd;
    QGraphicsScene *here;

signals:
    void move_L_signal();
    void move_R_signal();
    void shoot_W_signal();
    void start_moving_pla(); //signal
    void stop_this();
public slots:
    void platform_is_moving();
    void stop_timer(int);
    void restart_timer();
    void move_the_platform();

public:
    platform__build *_platform;
    platform__recreate *_platform_re;

    int PlatformTime;
};

#endif // MAINWINDOW_H
