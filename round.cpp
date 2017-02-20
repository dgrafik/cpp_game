#include "round.h"
#include <QFont>

Round::Round(QGraphicsItem *parent): QGraphicsTextItem(parent)
{

    setPlainText(QString("Round: 1"));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void Round::show(int a){
    setPlainText(QString("Round: ")+QString::number(a));
}

void Round::showround(){
    rounds++;
    setPlainText(QString("Round: ")+QString::number(rounds));
}
