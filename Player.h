#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>

class Player: public QGraphicsPixmapItem
{
public:
    Player ();
    void initPosition(QGraphicsScene *scene);
    void keyPressEvent(QKeyEvent *event);
};

#endif // PLAYER_H
