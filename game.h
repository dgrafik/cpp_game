#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include<QTimer>
#include "enemy.h"
#include <QGraphicsTextItem>
#include "round.h"
#include "health.h"
#include "resphlt.h"
#include <MyRect.h>
#include <score.h>
#include "walls.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget *parent=NULL);

    QGraphicsScene * scene;

    MyRect * rect = new MyRect();

    Round * round = new Round();

    Health * health = new Health;

    Resphlt * resp = new Resphlt();

    Score * score = new Score();

    Walls * walls = new Walls();

    int hp3 = 1;
    int hp4 = 2;
    int dupa = hp3;
    int dupa1 = hp4;

    bool check1 = true;

public slots:
    void centrowanie();

};

#endif // GAME_H
