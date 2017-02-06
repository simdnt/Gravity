#include "gballwrapper.h"
#include <QQmlProperty>
#include <QObject>
#include <QDebug>

GBallWrapper::GBallWrapper(QObject *parent) : QObject(parent)
{
    m_v_x = 0;
    m_v_y = 0;
    m_a_x = 0;
    m_a_y = 0;
}

void GBallWrapper::setGBall(QObject *a_ball)
{
    m_ball = a_ball;
    m_s_x = m_ball->property("x").toInt();
    m_s_y = m_ball->property("y").toInt();
}

int GBallWrapper::getX()
{
    return m_s_x;
}

int GBallWrapper::getY()
{
    return m_s_y;
}

void GBallWrapper::setA(int x, int y)
{
    m_a_x = x;
    m_a_y = y;
}

QObject *GBallWrapper::getBall()
{
    return m_ball;
}

void GBallWrapper::move()
{
    m_v_x = (m_v_x + m_a_x)%20;
    m_v_y = (m_v_y + m_a_y)%20;

    m_s_x = (m_s_x + m_v_x)%1366;
    m_s_y = (m_s_y + m_v_y)%768;

    if(m_s_x<0){m_s_x+=1366;}
    if(m_s_y<0){m_s_y+=768;}

    emit gBallMoved(m_ball,m_s_x,m_s_y);
}
