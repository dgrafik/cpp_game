#include "game.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include<QBrush>
#include "game.h"
#include <cstdlib>
#include <ctime>

Game* game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    srand(time(NULL));

    game = new Game();
    game->show();

    return a.exec();
}
