#include "Game.h"
#include "Health.h"
#include "Notification.h"
#include <QFont>

extern Game *game;

Health::Health()
{
    health = 3;

    setDefaultTextColor(Qt::white);
    setFont(QFont("times",18));
    setPos(x(),y()+25);

    print();
}

void Health::print ()
{
    setPlainText("HEALTH: " + QString::number(health));
}

void Health::decrease()
{
    if (health > 0)
    {
        health--;
        print();
        if (health == 0)
        {
            game->stop();
        }
    }
}

int Health::getHealth()
{
    return health;
}

