#include "Enemies.h"
#include "Enemy.h"
#include <QTimer>

Enemies::Enemies(QGraphicsScene *scene)
    :scene(scene)
{
    QTimer *timer = new QTimer();
    timer->start(2000); //milliseconds
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(spawn()));
}

void Enemies::spawn()
{
    Enemy *enemy = new Enemy();
    scene->addItem(enemy);
    enemy->start();
}
