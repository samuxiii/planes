#include "Enemies.h"
#include "Enemy.h"
#include "Game.h"
#include <QTimer>

extern Game *game;

Enemies::Enemies(QGraphicsScene *scene)
    :scene(scene), spawnTime(2000)
{
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(spawn()));
    game->notifier->registerSubscriber(*this);
}

Enemies::~Enemies()
{
    delete timer;
    game->notifier->unregisterSubscriber(*this);
}

void Enemies::spawn()
{
    Enemy *enemy = new Enemy();
    scene->addItem(enemy);
    enemy->start();
}

void Enemies::start()
{
    timer->start(spawnTime);
}

void Enemies::stop()
{
    timer->stop();
}

void Enemies::update(Notification notif)
{
    if (notif == Notification::GAMEOVER)
    {
        delete this;
    }
}
