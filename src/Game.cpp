#include "Game.h"
#include <QGraphicsTextItem>
#include <QTimer>
#include <QFont>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>

Game::Game ()
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

    //background
    setBackgroundBrush(QBrush(QImage(":/images/grass.png")));

    //sounds
    QMediaPlayer *mplayer = new QMediaPlayer();
    mplayer->setMedia(QUrl("qrc:/sounds/background.mp3"));
    mplayer->play();

    //game states notifier
    notifier = new Notifier();

    show();
}

Game::~Game()
{
    delete scene;
    delete player;
    delete enemies;
    delete score;
    delete health;
    delete notifier;
}

void Game::start()
{
    //score
    score = new Score();
    scene->addItem(score);

    //health
    health = new Health();
    scene->addItem(health);

    //player
    player = new Player();
    player->initPosition(scene);
    scene->addItem(player);

    //spawn enemies
    enemies = new Enemies(scene);
    enemies->start();
}

void Game::stop()
{
    enemies->stop();
    notifier->notify(Notification::GAMEOVER);
}
