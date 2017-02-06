#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QQmlEngine>
#include <QDebug>
#include <QList>
#include <QThread>
#include "gballwrapper.h"
#include "gravityengine.h"

class GravityEngine;

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);

    Q_INVOKABLE void addGBall(QObject *a_ball);
    Q_INVOKABLE void stop();
    Q_INVOKABLE QList<GBallWrapper*>* getGBalls();
signals:
    void gBallPositionChanged(QObject *ball, int x, int y);
public slots:
    void gBallMoved(QObject *ball, int x, int y);
private:
    QList<GBallWrapper*> *m_listOfGBalls;
    QThread *m_thread;
    GravityEngine *m_GEngine;
};

#endif // CONTROLLER_H
