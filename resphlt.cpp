#include "resphlt.h"
#include<QGraphicsScene>
#include <QTimer>
#include <QThread>
#include <MyRect.h>
#include <math.h>
#include <QList>
#include <iostream>
#include <mainwindow.h>
#include <QGraphicsPixmapItem>
#include <cstdlib>
#include <game.h>
#include <QObject>

extern Game * game;

Resphlt::Resphlt(): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/img/zycie.png"));

    rann = rand() % (748 - 95 + 1) + 95;
    rann1 = rand() % (1483 - 1185 + 1) + 1185;

    setScale(0.2);

    setPos(rann, rann1);

}

void Resphlt::resph(){
    rann = rand() % (748 - 95 + 1) + 95;
    rann1 = rand() % (1483 - 1185 + 1) + 1185;

    setScale(0.2);

    setPos(rann, rann1);
}
