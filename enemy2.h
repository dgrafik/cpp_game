#ifndef ENEMY2_H
#define ENEMY2_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <MyRect.h>
#include <iostream>

class Enemy2: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    Enemy2();
    static int heroPosx(int a);
    static int heroPosy(int b);

    //int hp2 = 2;

public slots:
    void followHero1();

private:
    int xrand;
    int yrand;
};

#endif // ENEMY2_H
