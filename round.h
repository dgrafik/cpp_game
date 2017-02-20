#ifndef ROUND_H
#define ROUND_H
#include <QGraphicsTextItem>


class Round: public QGraphicsTextItem
{
    Q_OBJECT
public:
    Round(QGraphicsItem * parent = 0);
    void show(int a);

public slots:
    void showround();

private:
    int rounds = 1;

};

#endif // ROUND_H
