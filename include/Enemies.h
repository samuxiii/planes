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

public slots:
    void spawn();

private:
    QGraphicsScene *scene;
};


#endif // ENEMIES_H
