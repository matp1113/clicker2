#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <stdlib.h>
#include <QPointF>
#include <QQuickItem>
#include <QPointF>
#include "movingPoint.h"

class Game : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool play READ isPlay WRITE setPlay NOTIFY playChanged)
public:
    explicit Game(QObject *parent = nullptr);
    bool isPlay() const;
    void setPlay(bool);
    int getX();
    int getY();
    void setPointVelocity(int vel);
    int getPointVelocity();

signals:
    void playChanged();
    void randomized(int xPar, int yPar);

public slots:
    void start();
    void stop();
    void addPoint();
    int receivePoints();

private:
    bool _play = false;
    MovingPoint *point;
    std::tuple<int, int> xy;
    int _velocity = 10;
    int _points = 100;
};

#endif // GAME_H
