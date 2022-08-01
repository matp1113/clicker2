#include "movingPoint.h"

#include <QDebug>
#include <math.h>
#include <random>

std::tuple<int, int> MovingPoint::rand_pos() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> randomized(0, velocity);
    x = x + round((randomized(mt))-(velocity/2));

    y = y + round((randomized(mt))-(velocity/2));

    if (x < 0){
        x = 0;
    }
    if(y < 0){
        y = 0;
    }
    if(x > 400){
        x = 400;
    }
    if(y > 400){
        y = 400;
    }
    qDebug() << "x=" << QString::number(x) << "y=" << QString::number(y) << " | ";
    return std::make_tuple(x, y);
}

