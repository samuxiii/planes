#include "Game.h"
#include <QGraphicsTextItem>
#include <QTimer>
#include <QFont>
#include <QMediaPlayer>

Game::Game (QWidget *parent)
{
    //window constants
    const int width = 800;
    const int height = 600;

    //scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, width, height);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(scene->width(), scene->height());

    //score
    score = new Score();
    scene->addItem(score);

    //health
    health = new Health();
    scene->addItem(health);

    //player
    player = new Player();
    player->setRect(0,0, 100, 100);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(this->width()/2, this->height() - player->rect().height());
    scene->addItem(player);

    //spawn enemies
    enemies = new Enemies(scene);
    QTimer *timer = new QTimer();
    timer->start(2000); //milliseconds
    QObject::connect(timer, SIGNAL(timeout()), enemies, SLOT(spawn()));

    //sounds
    QMediaPlayer *mplayer = new QMediaPlayer();
    mplayer->setMedia(QUrl("qrc:/../planes/Planes/sounds/background.mp3"));
    mplayer->play();

    show();
}
