#ifndef GBALLWRAPPER_H
#define GBALLWRAPPER_H

#include <QObject>

class GBallWrapper : public QObject
{
    Q_OBJECT
public:
    explicit GBallWrapper(QObject *parent = 0);

    Q_INVOKABLE void setGBall(QObject *a_ball);
    Q_INVOKABLE int getX();
    Q_INVOKABLE int getY();
    Q_INVOKABLE void setA(int x, int y);
    Q_INVOKABLE QObject* getBall();

public slots:
    void move();
signals:
    void gBallMoved(QObject *ball, int a_x, int a_y);
private:
    QObject *m_ball;
    int m_s_x;
    int m_s_y;
    int m_v_x;
    int m_v_y;
    int m_a_x;
    int m_a_y;
};

#endif // GBALLWRAPPER_H
