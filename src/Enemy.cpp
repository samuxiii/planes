#include "Game.h"
#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>

extern Game *game;

Enemy::Enemy()
    :QObject(),
     QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/enemy.png"));
    timer = new QTimer();
    game->notifier->registerSubscriber(*this);
}

Enemy::~Enemy()
{
    delete timer;
    game->notifier->unregisterSubscriber(*this);
}

void Enemy::start()
{
    /* create in random position
     * - It's needed a random number -> rand()
     * - Pass the obtained big random to a value inside the scene
     *   (calculate as "scene_width - enemy_width")
     */
    //TODO: improve the random
    int randomX = rand() % (int)(scene()->width() - this->pixmap().width());
    setPos(randomX, 0);

    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    if (game->health->getHealth() > 0)
    {
        setPos(x(), y()+5);

        if (pos().y() > scene()->height())
        {
            //decrease health if enemy touch the ground
            game->health->decrease();
            qDebug() << "Enemy out of scene. Deleted.";

            if (game->health->getHealth() > 0) //it's not a game over
            {
                scene()->removeItem(this);
                delete this;
            }
        }
    }
}

void Enemy::update(Notification notif)
{
    if (notif == Notification::GAMEOVER)
    {
        scene()->removeItem(this);
        delete this;
    }
}
