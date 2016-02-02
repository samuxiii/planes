#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include "Subscriber.h"

class Player: public QGraphicsPixmapItem, public Subscriber
{
public:
    Player();
    ~Player();
    void initPosition(QGraphicsScene *scene);
    void keyPressEvent(QKeyEvent *event);

    void update(Notification notif);
};

#endif // PLAYER_H
