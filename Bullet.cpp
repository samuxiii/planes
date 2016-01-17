#include "Bullet.h"
#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "Game.h"

extern Game *game;

Bullet::Bullet()
{
    setRect(0,0,10,50);

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    //impact!!
    QList<QGraphicsItem *> touchedItems = collidingItems();

    for (auto enemy : touchedItems)
    {
        if (typeid(*enemy) == typeid(Enemy))
        {
            game->score->increase();
            //clean up
            scene()->removeItem(enemy);
            scene()->removeItem(this);
            delete enemy;
            delete this;
            return;
        }
    }

    //moving
    setPos(x(), y()-10);
    if (pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Bullet out of scene. Deleted.";
    }
}
