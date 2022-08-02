#include "game.h"
#include <stdlib.h>
#include <QDebug>
#include <thread>
#include <chrono>

Game::Game(QObject *parent)
    : QObject{parent}
{
    point = new MovingPoint();
}

bool Game::isPlay() const
{
    return _play;
}

void Game::setPlay(bool play)
{
    _play = play;
    emit playChanged();
    if(play){
        start();
    }
}

void Game::start(){
    _play = true;
    qDebug() << "enter start()";
    while(true){
        QCoreApplication::processEvents();
        if(_play == false){
            break;
        }
        xy = point->rand_pos();
        qDebug() << "from game: " << "x=" << QString::number(getX()) << "y=" << QString::number(getY()) << " | ";
        emit randomized(getX(), getY());
        std::this_thread::sleep_for(std::chrono::nanoseconds(100000000));
    }
}

void Game::stop()
{
    setPlay(false);
}

void Game::addPoint()
{
    if(_play == true){
        _points = _points + 1;
    }
}

int Game::receivePoints()
{
    return _points;
}

int Game::getX()
{
    return std::get<0>(xy);
}

int Game::getY()
{
    return std::get<1>(xy);
}

void Game::setPointVelocity(int vel)
{
    point->setVelocity(vel);
}

int Game::getPointVelocity()
{
    return point->getVelocity();
}
