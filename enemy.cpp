#include "enemy.h"
#include<QGraphicsScene>
#include <QTimer>
#include <QSignalMapper>
#include <MyRect.h>
#include <math.h>
#include<QList>
#include <iostream>
#include <mainwindow.h>
#include <QGraphicsScene>
#include <game.h>
#include <cstdlib>

int m,n;
int k;

extern Game * game;

Enemy::Enemy(): QObject(), QGraphicsPixmapItem()
{
    int ranx = rand() % (2367 - 1376 + 1) + 1367;
    int rany = rand() % (1014 - 150 + 1) + 150;
    setPos(ranx, rany);

    setPixmap(QPixmap(":/img/Przeciwnik.png"));
    setScale(0.23);

    //QTimer * timer3 = new QTimer(this);
    connect(game->rect, SIGNAL(follow()), this, SLOT(followHero()));
    //timer3->start();
}

int Enemy::heroPosx(int a){
    m = a;
    return m;
}

int Enemy::heroPosy(int b){
    n = b;
    return n;
}

void Enemy::followHero(){
    int dx,dy;
    double hyp=0;
    dx=m-x();
    dy=n-y();
    hyp=sqrt(dx*dx+dy*dy);
    if(hyp<300){
        dx *= 1.15/hyp;
        dy *= 1.15/hyp;
        setPos(x()+dx, y()+dy); //Moduł Ania !
    }
}
