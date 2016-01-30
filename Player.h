#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

class Player: public QGraphicsPixmapItem
{
public:
    Player ();
    void initPosition(QGraphicsScene *scene);
    void keyPressEvent(QKeyEvent *event);

private:
    QMediaPlayer * bulletSound;
};

#endif // PLAYER_H
