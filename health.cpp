#include "health.h"
#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    health = 10;

    setPlainText(QString("Health: ")+QString::number(health));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void Health::drawhlt(){
    setPlainText(QString("Health: ")+QString::number(health));

}
void Health::drawhlt1(){
    setPlainText(QString("Health: ")+QString::number(health));
}
