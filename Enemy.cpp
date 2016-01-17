#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include "Game.h"

extern Game *game;

Enemy::Enemy()
{
    setRect(0,0,100,100);
}

void Enemy::start()
{
    /* create in random position
     * - It's needed a random number -> rand()
     * - Pass the big obtained random to a value inside the scene
     *   (it has to calculate with the "scene_width - enemy_width")
     */
    //TODO: improve the random
    int randomX = rand() % (int)(scene()->width() - this->rect().width());
    setPos(randomX, 0);

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    setPos(x(), y()+5);

    if (pos().y() > scene()->height())
    {
        //decrease health if enemy touch the ground
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
        qDebug() << "Enemy out of scene. Deleted.";
    }
}
