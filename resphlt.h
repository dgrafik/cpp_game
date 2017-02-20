#ifndef RESPHLT_H
#define RESPHLT_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <MyRect.h>
#include <iostream>

class Resphlt: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT;
public:
    Resphlt();

public slots:
    void resph();
private:
    int rann;
    int rann1;

};

#endif // RESPHLT_H
