#ifndef GRAVITYENGINE_H
#define GRAVITYENGINE_H

#include <QObject>
#include <QThread>
#include <QList>
#include <QDebug>
#include "controller.h"

class Controller;

class GravityEngine : public QObject
{
    Q_OBJECT
public:
    explicit GravityEngine(QObject *parent = 0);
    void setController(Controller *a_ctrl);
    void doSetup(QThread *a_Tread);

signals:

public slots:
    void doWork();
    void stop();
private:
    Controller *m_ctrl;
    bool stopFlag;
};

#endif // GRAVITYENGINE_H
