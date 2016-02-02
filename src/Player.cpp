#include <Game.h>
#include <Player.h>
#include <Bullet.h>
#include <Enemy.h>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

extern Game *game;

Player::Player()
    :QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/player.png"));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    game->notifier->registerSubscriber(*this);
}

Player::~Player()
{
    game->notifier->unregisterSubscriber(*this);
}

void Player::initPosition(QGraphicsScene *scene)
{
    /* scene pointer needed, the scene could not be constructed yet */
    setPos(scene->width()/2 - this->pixmap().width()/2,
           scene->height() - this->pixmap().height());
}

void Player::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << "Key pressed";
    int movement = 20;

    if (event->key() == Qt::Key_Left){
        //left limit
        if (pos().x() > 0)
            setPos(x()-movement, y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        //right limit
        if (pos().x() + this->pixmap().width() < scene()->width())
        {
            setPos(x()+movement, y());
        }
    }
    else if (event->key() == Qt::Key_Space)
    {
        qDebug() << "Bullet shooted";
        Bullet *bullet = new Bullet();
        //where the bullet comes out
        bullet->setPos(x() + (this->pixmap().width()/2 - bullet->pixmap().width()/2), y());
        scene()->addItem(bullet);
    }
    else if (event->key() == Qt::Key_Escape)
    {
        exit(0);
    }
}

void Player::update(Notification notif)
{
   if (notif == Notification::GAMEOVER)
   {
      delete this;
   }
}
