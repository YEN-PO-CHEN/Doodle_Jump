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
#include "monster.h"
#include "monster1.h"
#include "monster2.h"
#include "monster3.h"
#include "monster4.h"
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
    void create_the_monster();
    void deadth();
    void ctor_tool_vector();
    void put_tool();
    bool collide(int);
    bool monster_is_alive = false;
    bool rocket_or_not = false;
    bool shield_or_not = false;
    int PlatformTime = 50; //Stop_timer
    int jump_time = 0;     //Y_jump()
    double velocity = DOODLE_VEL;
    int show_on_lcd = 0;
    int _5000_cycle = 0;
    int death_vel;
    double pause_X = Default_X, pause_Y = Default_Y;
    vector<QPixmap> tool_string_pix;
    vector<QPixmap> tool_rocket_pix;
    vector<QGraphicsPixmapItem *> tool_string;
    QGraphicsPixmapItem *tool_rocket;

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *timer;
    QTimer *mon_timer;
    doodle *dood;
    vector<bullet *> bul;
    background *bcgd;
    QGraphicsScene *here;
    monster *mon;
    QPixmap hazard_pix;
    QGraphicsPixmapItem *hazard_item;
    vector<QPixmap> string;
    vector<QPixmap> rocket;
signals:
    void move_L_signal();
    void move_R_signal();
    void shot_W_signal();
    void mons_M_signal();

public slots:
    void Y_jump();
    void platform_is_moving();
    void shooot();
    void pause();
    void resta();
    void mon_move();
    void afterdeath();
    void doodle_death();
    void return_to_orignal();
};

#endif // MAINWINDOW_H
