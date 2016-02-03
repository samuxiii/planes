#include "Enemies.h"
#include "Enemy.h"
#include "Game.h"
#include <QTimer>

extern Game *game;

Enemies::Enemies(QGraphicsScene *scene)
    :scene(scene)
{
    QTimer *timer = new QTimer();
    timer->start(2000); //milliseconds
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(spawn()));
    game->notifier->registerSubscriber(*this);
}

Enemies::~Enemies()
{
    game->notifier->unregisterSubscriber(*this);
}

void Enemies::spawn()
{
    Enemy *enemy = new Enemy();
    scene->addItem(enemy);
    enemy->start();
}

void Enemies::update(Notification notif)
{
    if (notif == Notification::GAMEOVER)
    {
        delete this;
    }
}
