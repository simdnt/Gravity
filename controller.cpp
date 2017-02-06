#include "controller.h"


Controller::Controller(QObject *parent) : QObject(parent)
{
    m_listOfGBalls = new QList<GBallWrapper*>();

    m_thread = new QThread();
    m_GEngine = new GravityEngine();
    m_GEngine->setController(this);
    m_GEngine->doSetup(m_thread);
    m_GEngine->moveToThread(m_thread);
    m_thread->start();
    QThread::sleep(0);
}

void Controller::addGBall(QObject *a_ball)
{
    GBallWrapper *ball = new GBallWrapper(this);
    m_listOfGBalls->append(ball);
    ball->setGBall(a_ball);
    connect(ball,SIGNAL(gBallMoved(QObject*,int,int)),this,SLOT(gBallMoved(QObject*,int,int)));
}

void Controller::stop()
{
    foreach (GBallWrapper *ball, *m_listOfGBalls) {
        disconnect(ball,SIGNAL(gBallMoved(QObject*,int,int)),this,SLOT(gBallMoved(QObject*,int,int)));
    }
    m_GEngine->stop();
    m_listOfGBalls->clear();
    QThread::msleep(200);
    m_thread->exit();
    QThread::msleep(100);
}

QList<GBallWrapper *> *Controller::getGBalls()
{
    return m_listOfGBalls;
}

void Controller::gBallMoved(QObject *ball, int x, int y)
{
    emit gBallPositionChanged(ball,x,y);
}
