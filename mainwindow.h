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
    mainbullet _main;
    vector<int> Plt_vec_v;
    platform__build *_platform;
    platform__recreate *_platform_re;
    void ver(int);
    void hor(int);
    void keyPressEvent(QKeyEvent *e);
    void ctor_vector();
    int PlatformTime = 50; //Stop_timer
    int jump_time = 0;     //Y_jump()
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *timer;
    doodle *dood;
    vector<bullet *> bul;
    background *bcgd;
    QGraphicsScene *here;
signals:
    void move_L_signal();
    void move_R_signal();
    void shot_W_signal();

public slots:
    void Y_jump();
    void platform_is_moving();
    void shooot();
};

#endif // MAINWINDOW_H
