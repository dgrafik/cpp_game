#include "walls.h"
#include "game.h"
#include <QGraphicsScene>
#include <QTimer>
#include <MyRect.h>
#include "ios"

extern Game * game;

Walls::Walls()
{
    setPixmap(QPixmap(":/img/3 poprawione.png"));
    setPos(0,0); 
}

