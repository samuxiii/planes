#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "Player.h"
#include "Enemies.h"
#include "Score.h"
#include "Health.h"

class Game: public QGraphicsView
{
public:
    Game ();

    QGraphicsScene *scene;
    Player *player;
    Enemies *enemies;
    Score *score;
    Health *health;
};

#endif // GAME_H
