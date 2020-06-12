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

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *pic;
    QGraphicsTextItem *text;
    QGraphicsItemGroup *group;
    QTimer *timer;
    doodle *dood;
    vector<bullet *> bul;
    background *bcgd;
    QGraphicsScene *here;

signals:
    void move_L_signal();
    void move_R_signal();
    void shoot_W_signal();

public:
    platform__build *_platform;
};

#endif // MAINWINDOW_H
