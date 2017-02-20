#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 0;

    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

//void Score::highScore(){
//    QFile file("in.txt");
//        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
//            return;

//        while (!file.atEnd()) {
//            QByteArray line = file.readLine();
//            process_line(line);
//        }
//}

void Score::ad(){
    score++;
    setPlainText(QString("Score: ")+QString::number(score));
}

void Score::add1(){
    score = score + 2;
    setPlainText(QString("Score: ")+QString::number(score));
}
