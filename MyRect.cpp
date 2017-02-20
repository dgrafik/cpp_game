#include "enemy.h"
#include "enemy2.h"
#include "Bullet.h"
#include <QKeyEvent>
#include "iostream"
#include <math.h>
#include"game.h"
#include <mainwindow.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <walls.h>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include "resphlt.h"
#include <MyRect.h>
#include "score.h"

extern Game * game;

MyRect::MyRect(): QObject(), QGraphicsPixmapItem(){

    //setPixmap(QPixmap(":/img/postać 4.png"));
    setScale(0.5);

}

void MyRect::Event(){

    if (left == true)
    {
        moveBy(-speed-0.3, 0);
        //setPixmap(QPixmap(":/img/postać 1.png"));
        emit zapdejtujEkran();
        emit follow();
        emit follow1();
        emit mov();

        left1 = true;
        right1 = false;
        up1 = false;
        down1 = false;

        QList<QGraphicsItem *> colliding_items4 = collidingItems();
        for (int i = 0, n = colliding_items4.size(); i < n; ++i){
            if (typeid(*(colliding_items4[i])) == typeid(Walls)){
                moveBy(+1,0);
                return;
            }
        }
    }
    if (right == true)
    {
        moveBy(speed+0.3, 0);
        //setPixmap(QPixmap(":/img/postać 2.png"));
        emit zapdejtujEkran();
        emit follow();
        emit follow1();
        emit mov();

        right1 = true;
        left1 = false;
        up1 = false;
        down1 = false;

        QList<QGraphicsItem *> colliding_items4 = collidingItems();
        for (int i = 0, n = colliding_items4.size(); i < n; ++i){
            if (typeid(*(colliding_items4[i])) == typeid(Walls)){
                moveBy(-1,0);
                return;
            }
        }
    }
    if (up == true)
    {
        moveBy(0,-speed);
        //setPixmap(QPixmap(":/img/postać 3.png"));
        emit zapdejtujEkran();
        emit follow();
        emit follow1();

        up1 = true;
        down1 = false;
        right1 = false;
        left1 = false;

        QList<QGraphicsItem *> colliding_items4 = collidingItems();
        for (int i = 0, n = colliding_items4.size(); i < n; ++i){
            if (typeid(*(colliding_items4[i])) == typeid(Walls)){
                moveBy(0,+1);
                return;
            }
        }
    }
    if (down == true)
    {
        moveBy(0,speed);
        //setPixmap(QPixmap(":/img/postać 4.png"));
        emit zapdejtujEkran();
        emit follow();
        emit follow1();

        down1 = true;
        up1 = false;
        right1 = false;
        left1 = false;

        QList<QGraphicsItem *> colliding_items4 = collidingItems();
        for (int i = 0, n = colliding_items4.size(); i < n; ++i){
            if (typeid(*(colliding_items4[i])) == typeid(Walls)){
                moveBy(0,-1);
                return;
            }
        }
    }

}

void MyRect::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_A){
        setPixmap(QPixmap(":/img/postać 1.png"));
        left = true;
        std::cout<<"ggg"<<std::endl;

    }else if (event->key() == Qt::Key_D){
        ri();
        right = true;
    }

    if (event->key() == Qt::Key_W){
        setPixmap(QPixmap(":/img/postać 3.png"));
        up = true;

    }else if (event->key() == Qt::Key_S){
        setPixmap(QPixmap(":/img/postać 4.png"));
        down = true;

    }else if(event->key() == Qt::Key_Space){

        shoot = true;
        std::cout<<ilejest1<<std::endl;
        int ilejest3 = ilejest1 + ilejest2;
        if(ilejest3 == 0){
                emit next();
                emit tt();
            }


        Bullet * bullet = new Bullet();
        bullet->setPos(this->x()+12.5, this->y()+15);
        bullet->setScale(0.075);
        connect(bullet, SIGNAL(scr()), game->score, SLOT(ad()));
        connect(bullet, SIGNAL(scr1()), game->score, SLOT(add1()));

        scene()->addItem(bullet);

        QTimer * timer = new QTimer;
        connect(timer, SIGNAL(timeout()), bullet, SLOT(move()));
        timer->start(1);
    }

    Enemy::heroPosx(x());
    Enemy::heroPosy(y());
    Enemy2::heroPosx(x());
    Enemy2::heroPosy(y());
}

void MyRect::keyReleaseEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_A){
        left = false;

    }else if (event->key() == Qt::Key_D){
        right = false;
    }

    if (event->key() == Qt::Key_W){
        up = false;

    }else if (event->key() == Qt::Key_S){
        down = false;
    }else if(event->key() == Qt::Key_Space){
        shoot = false;
    }

}

int MyRect::heroPox(int x){
    MyRect::m1 = x;
    return m1;
}

int MyRect::heroPoy(int y){
    MyRect::n1 = y;
    return n1;
}

void MyRect::spawn(){
    if(counter1 != ilosc1){
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
    counter1++;

    }
}

void MyRect::spawn1(){
    if(counter2 != ilosc2){
    Enemy2 * enemy2 = new Enemy2;
    scene()->addItem(enemy2);
    counter2++;

    }
}

void MyRect::checkColl(){
    QList<QGraphicsItem *> colliding_items3 = collidingItems();

    for (int i = 0, n = colliding_items3.size(); i < n; ++i){
        if (typeid(*(colliding_items3[i])) == typeid(Resphlt)){

            game->health->health++;
            //game->check1 = false;
            emit hell();
            emit hell1();

            Resphlt * respo = new Resphlt();
            scene()->addItem(respo);

            scene()->removeItem(colliding_items3[i]);
            delete colliding_items3[i];

            return;
        }if (typeid(*(colliding_items3[i])) == typeid(Enemy)){

            game->health->health--;
            emit hell1();

            return;
        }if (typeid(*(colliding_items3[i])) == typeid(Enemy2)){

            game->health->health--;
            emit hell1();

            return;
        }
    }

}

void MyRect::nextRound(){

    ilosc1 = ilosc1 + 3;
    ilosc2 = ilosc2 + 2;

    counter1 = 0;
    counter2 = 0;

    ilejest1 = ilosc1;
    ilejest2 = ilosc2;
    //int ilejest3 = ilejest1 + ilejest2;

    game->hp3 += 1;
    game->dupa = game->hp4;

    game->hp4 += 1;
    game->dupa1 = game->hp4;

    emit roundd();
}

void MyRect::ri(){
    setPixmap(QPixmap(":/img/postać 2.png"));
    std::cout<<"kupa";
}
