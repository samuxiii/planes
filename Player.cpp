#include <Player.h>
#include <Bullet.h>
#include <Enemy.h>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

void Player::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Key pressed";
    int movement = 20;

    if (event->key() == Qt::Key_Left)
    {
        //left limit
        if (pos().x() > 0)
            setPos(x()-movement, y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        //right limit
        if (pos().x() + this->rect().width() < scene()->width())
            setPos(x()+movement, y());
    }
    else if (event->key() == Qt::Key_Space)
    {
        qDebug() << "Bullet shooted";
        Bullet *bullet = new Bullet();
        bullet->setPos(x() + (this->rect().width()/2 - bullet->rect().width()/2),y());
        scene()->addItem(bullet);
    }
    else if (event->key() == Qt::Key_Escape)
    {
        exit(0);
    }
}

