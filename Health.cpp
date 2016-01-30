#include "Health.h"
#include <QFont>

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
    health--;
    print();
}

int Health::getHealth()
{
    return health;
}

