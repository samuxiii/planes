#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem
{
public:
    Score ();
    void increase ();
    int getScore ();

private:
    int score;
    void print();
};

#endif // SCORE_H
