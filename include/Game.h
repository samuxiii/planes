#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "Player.h"
#include "Enemies.h"
#include "Score.h"
#include "Health.h"
#include "Notifier.h"

class Game: public QGraphicsView
{
public:
    Game();
    ~Game();
    void start();
    void stop();

    QGraphicsScene *scene;
    Player *player;
    Enemies *enemies;
    Score *score;
    Health *health;
    Notifier *notifier;
};

#endif // GAME_H
