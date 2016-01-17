#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent)
{
    health = 3;

    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
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

