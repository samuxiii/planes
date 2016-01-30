#include "Score.h"
#include <QFont>

Score::Score()
{
    score = 0;
    print();
}

void Score::print ()
{
    setPlainText("SCORE: " + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",18));
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

