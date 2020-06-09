#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "_basic.h"
#include "doodle.h"
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

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QGraphicsPixmapItem *pic;
    QGraphicsTextItem *text;
    QGraphicsItemGroup *group;
    QTimer *timer;
    doodle *dood;
signals:
    void move_L_signal();
    void move_R_signal();
};

#endif // MAINWINDOW_H
