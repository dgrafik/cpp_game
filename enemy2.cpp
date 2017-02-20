#include "enemy2.h"
#include<QGraphicsScene>
#include <QTimer>
#include <QSignalMapper>
#include <MyRect.h>
#include <math.h>
#include<QList>
#include <iostream>
#include <iostream>
#include <QThread>
#include <QGraphicsPixmapItem>
#include <game.h>

extern Game * game;

int n2,m2;

Enemy2::Enemy2(): QObject(), QGraphicsPixmapItem()
{
    xrand = rand() % (2408 - 914 + 1) + 914;
    yrand = rand() % (1443 - 1215 + 1) + 1215;
    setPos(xrand, yrand);

    connect(game->rect, SIGNAL(follow1()), this, SLOT(followHero1()));
    setPixmap(QPixmap(":/img/Przeciwnik 2.png"));
    setScale(0.23);
}

int Enemy2::heroPosx(int a){
    m2 = a;
    return m2;
}

int Enemy2::heroPosy(int b){
    n2 = b;
    return n2;
}

void Enemy2::followHero1(){
    int dx,dy;
    float hyp=0;
    dx=m2-x();
    dy=n2-y();
    hyp=sqrt(dx*dx+dy*dy);
    //std::cout<<dx<<std::endl;
    if(hyp<400){
        dx *= 1.3/hyp;
        dy *= 1.3/hyp;
        setPos(x()+dx, y()+dy);
    }

}
