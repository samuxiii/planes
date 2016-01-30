#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem
{
public:
    Health ();
    void decrease ();
    int getHealth ();

private:
    int health;
    void print();
};

#endif // HEALTH_H
