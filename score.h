#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFile>

class Score: public QGraphicsTextItem
{
    Q_OBJECT
public:
    Score(QGraphicsItem * parent =0);
    //void highScore();

    int score;

public slots:
    void ad();
    void add1();
};

#endif // SCORE_H
