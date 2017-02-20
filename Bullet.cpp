#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include "typeinfo"
#include <QList>
#include "game.h"
#include <QList>
#include "enemy.h"
#include "MyRect.h"
#include "walls.h"
#include "enemy2.h"

extern Game * game;

Bullet::Bullet(){

    //setPixmap(QPixmap(":/img/Strzala.png"))
    //timer2 = new QTimer();
    //connect(timer2,SIGNAL(timeout()),this,SLOT(move()));

    //timer2->start(7);

    //up2 = game->rect->up1;
    if(game->rect->up1 == true){
        up2 = true;
        setPixmap(QPixmap(":/img/Strzala.png"));
    }

    if(game->rect->down1 == true){
        down2 = true;
        setPixmap(QPixmap(":/img/Strzala.png"));
        setRotation(180);
    }

    if(game->rect->right1 == true){
        right2 = true;
        setPixmap(QPixmap(":/img/Strzala.png"));
        setRotation(90);
    }

    if(game->rect->left1 == true){
        left2 = true;
        setPixmap(QPixmap(":/img/Strzala.png"));
        setRotation(270);

    }



}

void Bullet::move(){

    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){


            if(game->rect->ilejest1 == -1){
                game->rect->ilejest1 = 0;
            }
            game->hp3--;
            if(game->hp3 == 0){
                emit scr();
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                game->hp3 = game->dupa;
                game->rect->ilejest1--;
            }

            scene()->removeItem(this);

            //delete timer2;
            delete this;
            return;
        }
    }

    QList<QGraphicsItem *> colliding_items2 = collidingItems();
    for (int i = 0, n = colliding_items2.size(); i < n; ++i){
        if (typeid(*(colliding_items2[i])) == typeid(Enemy2)){


            game->hp4--;
            if(game->hp4 == 0){
                emit scr1();
                scene()->removeItem(colliding_items2[i]);
                delete colliding_items2[i];
                game->hp4 = game->dupa1;
                game->rect->ilejest2--;
            }

            scene()->removeItem(this);

            //delete timer2;
            delete this;
            return;
        }
    }

    QList<QGraphicsItem *> colliding_items1 = collidingItems();

    for (int i = 0, n = colliding_items1.size(); i < n; ++i){
        if (typeid(*(colliding_items1[i])) == typeid(Walls)){

            scene()->removeItem(this);

            //delete colliding_items1[i];
            //delete timer2;
            delete this;
            return;
        }
    }

    up2 = game->rect->up1;
    if(up2 == true){
        setPos(x(),y()-v);
        setPixmap(QPixmap(":/img/Strzala.png"));
    }

    if(down2 == true){
        setPos(x(), y()+v);
        setPixmap(QPixmap(":/img/Strzala.png"));
        setRotation(180);
    }

    if(right2 == true){
        setPos(x()+v, y());
        setPixmap(QPixmap(":/img/Strzala.png"));
        setRotation(90);
    }

    if(left2 == true){
        setPos(x()-v,y());
        setPixmap(QPixmap(":/img/Strzala.png"));
        setRotation(270);

    }

    //setPos(x(), y()-10);

    if (pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
    if(pos().y() > 1600){
        scene()->removeItem(this);
        delete this;
    }

    if(pos().x() >2560){
        scene()->removeItem(this);
        delete this;
        //std::cout<<"gigaset"<<std::endl;
    }

    if(pos().x() < 0 ){
        scene()->removeItem(this);
        delete this;
    }
}


//dorobić, żeby strzałka miała kierunek i czytała z gracza (kierunek -> w momencie wystrzelenia)
