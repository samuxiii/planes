#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "Subscriber.h"

class Enemy: public QObject,
    public QGraphicsPixmapItem,
    public Subscriber
{
    Q_OBJECT
public:
    Enemy ();
    ~Enemy ();
    void start();
    void update(Notification notif);

public slots:
    void move ();
};

#endif // ENEMY_H
