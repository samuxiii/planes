#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QMediaPlayer>

class Player: public QGraphicsRectItem
{
public:
    Player (QGraphicsItem *parent = 0);
    void keyPressEvent(QKeyEvent *event);

private:
    QMediaPlayer * bulletSound;
};

#endif // PLAYER_H
