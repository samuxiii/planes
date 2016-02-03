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
    game->notifier->registerSubscriber(*this);
}

Enemy::~Enemy()
{
    game->notifier->unregisterSubscriber(*this);
}

void Enemy::start()
{
    /* create in random position
     * - It's needed a random number -> rand()
     * - Pass the big obtained random to a value inside the scene
     *   (it has to calculate with the "scene_width - enemy_width")
     */
    //TODO: improve the random
    int randomX = rand() % (int)(scene()->width() - this->pixmap().width());
    setPos(randomX, 0);

    QTimer *timer = new QTimer();
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

            if (game->health->getHealth() <= 0)
            {
                game->notifier->notify(Notification::GAMEOVER);
            }
            else
            {
                scene()->removeItem(this);
                qDebug() << "Enemy out of scene. Deleted.";
                delete this;
            }
        }
    }
}

void Enemy::update(Notification notif)
{
    if (notif == Notification::GAMEOVER)
    {
        delete this;
    }
}
