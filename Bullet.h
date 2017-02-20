#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>


class Bullet: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet();

    //QTimer * timer2;

public slots:
    void move();

private:
    const int v = 10;
    bool right2 = false;
    bool left2 = false;
    bool up2 = false;
    bool down2 = false;

signals:
    void scr();
    void scr1();
};

#endif // BULLET_H
