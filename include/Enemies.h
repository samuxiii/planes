#ifndef ENEMIES_H
#define ENEMIES_H

#include <QObject>
#include <QGraphicsScene>
#include "Subscriber.h"

class Enemies: public QObject, public Subscriber
{
    Q_OBJECT
public:
    Enemies(QGraphicsScene *scene);
    ~Enemies();
    void update(Notification notif);
    void start();
    void stop();

public slots:
    void spawn();

private:
    QGraphicsScene *scene;
    QTimer* timer;
    int spawnTime; //milliseconds
};


#endif // ENEMIES_H
