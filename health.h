#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>


class Health: public QGraphicsTextItem
{
    Q_OBJECT
public:
    Health(QGraphicsItem * parent = 0);
    int health;

public slots:
    void drawhlt();
    void drawhlt1();

};

#endif // HEALTH_H
