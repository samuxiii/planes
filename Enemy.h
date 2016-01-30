#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy ();
    void start();

public slots:
    void move ();
};

#endif // ENEMY_H
