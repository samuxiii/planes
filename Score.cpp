#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent)
{
    score = 0;
    print();
}

void Score::print ()
{
    setPlainText("SCORE: " + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase()
{
    score++;
    print();
}

int Score::getScore()
{
    return score;
}

