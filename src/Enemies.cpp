#include "Enemies.h"
#include "Enemy.h"

Enemies::Enemies(QGraphicsScene *scene)
    :scene(scene)
{}

void Enemies::spawn()
{
    Enemy *enemy = new Enemy();
    scene->addItem(enemy);
    enemy->start();
}
