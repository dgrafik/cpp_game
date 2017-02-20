#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <MyRect.h>
#include <iostream>

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    Enemy();
    static int heroPosx(int a);
    static int heroPosy(int b);

    //int hp1 = 2;

public slots:
    void followHero();

};
#endif // ENEMY_H
