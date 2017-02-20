#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "enemy.h"
#include <QGraphicsPixmapItem>
#include <enemy2.h>
#include <Bullet.h>


class MyRect: public QObject, public QGraphicsPixmapItem{
    //friend class Enemy;
    Q_OBJECT
public:
    MyRect();

    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);

    int n1 = 0;
    int m1 = 0;

    int ilosc1 = 10;
    int counter1 = 0;

    int ilosc2 = 8;
    int counter2 = 0;

    int ilejest1 = ilosc1;
    int ilejest2 = ilosc2;


    bool right1 = false;
    bool left1 = false;
    bool up1 = false;
    bool down1 = false;

public slots:
    void spawn();
    void spawn1();

    void checkColl();
    void Event();

    void nextRound();

private:

    const double speed = 0.5;

    int heroPox(int x);
    int heroPoy(int y);

    void ri();

    bool right = false;
    bool left = false;
    bool up = false;
    bool down = false;
    bool shoot = false;

signals:
    void zapdejtujEkran();
    void next();
    void tt();
    void hell();
    void hell1();
    void roundd();
    void follow();
    void follow1();
    void mov();
};

#endif // kończ MYRECT_H
