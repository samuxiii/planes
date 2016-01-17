#include <QApplication>
#include <QGraphicsScene>
#include <Player.h>
#include <Enemies.h>
#include <QGraphicsView>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //window constants
    const int width = 800;
    const int height = 600;

    //scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, width, height);

    //view
    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(scene->width(), scene->height());
    view->show();

    //player
    Player *player = new Player();
    player->setRect(0,0, 100, 100);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(view->width()/2, view->height() - player->rect().height());
    scene->addItem(player);

    //spawn enemies
    Enemies *enemies = new Enemies(scene);
    QTimer *timer = new QTimer();
    timer->start(2000); //milliseconds
    QObject::connect(timer, SIGNAL(timeout()), enemies, SLOT(spawn()));

    return a.exec();
}
