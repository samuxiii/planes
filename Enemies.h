#ifndef ENEMIES_H
#define ENEMIES_H

#include <QObject>
#include <QGraphicsScene>

class Enemies: public QObject
{
    Q_OBJECT
private:
    QGraphicsScene *scene;

public:
    Enemies(QGraphicsScene *scene);

public slots:
    void spawn();
};


#endif // ENEMIES_H
