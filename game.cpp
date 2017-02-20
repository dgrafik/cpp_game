#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include "MyRect.h"
#include "enemy.h"
#include "enemy2.h"
#include"stdio.h"
#include "score.h"
#include "health.h"
#include "resphlt.h"
#include "ios"
#include "round.h"
#include "button.h"
#include "walls.h"
#include "QGraphicsPixmapItem"
#include <Bullet.h>
#include <mainwindow.h>
#include <QDebug>
#include <QThread>

Game::Game(QWidget *parent)
{

        scene = new QGraphicsScene();
        scene->setSceneRect(0,0,2560,1600);

        rect->setPos(150, 100);

        rect->setPixmap(QPixmap(":/img/postać 4.png"));

        scene->addItem(rect);


        rect->setFlag(QGraphicsItem::ItemIsFocusable);
        rect->setFocus();

        //QThread * sometread = new QThread; //?
        //std::cout<<"From second thread: "<<QThread::currentThreadId();

        //QTimer * timer = new QTimer(0); // parent must be null
        //timer-> setInterval(1); //!!
        //timer-> moveToThread(somethread);
        //connect(...)...


        QTimer * timer = new QTimer;

        //timer->moveToThread(sometread);
        connect(timer,SIGNAL(timeout()),rect,SLOT(spawn()));
        connect(timer,SIGNAL(timeout()),rect,SLOT(spawn1()));

        //QTimer * timers = new QTimer;
        connect(timer,SIGNAL(timeout()),rect,SLOT(checkColl()));
        connect(timer, SIGNAL(timeout()), rect, SLOT(Event()));
        //timers->start(3000);
        timer->start(1);

        //sometread->start();
        //connect(rect, SIGNAL(mov()), rect, SLOT(Event()));

        scene->addItem(walls);

        connect(rect, SIGNAL(zapdejtujEkran()), this, SLOT(centrowanie()));
        connect(rect, SIGNAL(tt()), rect, SLOT(nextRound()));

        scene->addItem(resp);

        health->setPos(health->x(), health->y()+25);
        scene->addItem(health);
        connect(rect, SIGNAL(hell()), health, SLOT(drawhlt()));
        connect(rect, SIGNAL(hell1()), health, SLOT(drawhlt1()));
        connect(rect, SIGNAL(hell1()), resp, SLOT(resph()));
        connect(rect ,SIGNAL(roundd()), round, SLOT(showround()));



        round->setPos(round->x(), round->y()+50);
        scene->addItem(round);
        scene->addItem(score);

        setScene(scene);
        //setScene(scene2);


        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        centerOn(rect);
        //view->ensureVisible(rect);

        setFixedSize(900,800);
        setBackgroundBrush(QBrush(QImage(":/img/ZombieWaveostatecznie.png")));


        std::cout<<"From main thread: "<<QThread::currentThreadId();

        //Serduszko zapierdala jak pojebane, gdy zombie wejdzie na gracza !

}

void Game::centrowanie(){
    centerOn(rect);
}
