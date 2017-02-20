#ifndef WALLS_H
#define WALLS_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Walls: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Walls();

//public slots:
    //void checkColl();
};

#endif // WALLS_H
