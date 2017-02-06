#include "gravityengine.h"

GravityEngine::GravityEngine(QObject *parent): QObject(parent)
{
    this->stopFlag = false;
}

void GravityEngine::setController(Controller *a_ctrl)
{
    m_ctrl = a_ctrl;
}

void GravityEngine::doSetup(QThread *a_Thread)
{
    connect(a_Thread,SIGNAL(started()),this,SLOT(doWork()));
}

void GravityEngine::doWork()
{
    while(true){
        //qDebug() << "Thread läuft";
        if(stopFlag){
            break;
        }
        QThread::msleep(100);
        QList<GBallWrapper*>* l_GBalls = m_ctrl->getGBalls();
        int l_count = l_GBalls->count();
        if(l_count>1){
            for (int i = 0; i < l_count; ++i) {
                GBallWrapper *l_gb = l_GBalls->at(i);
                int l_ax = 0;
                int l_ay = 0;
                int l_s_x = l_gb->getX();
                int l_s_y = l_gb->getY();
                for (int j = 0; j < l_count; ++j) {
                    if(i!=j){
                        GBallWrapper *l_gbi = l_GBalls->at(j);
                        int l_diffX = l_gbi->getX() - l_s_x;
                        int l_diffY = l_gbi->getY() - l_s_y;
                        int l_diffsum = 0;
                        if(l_diffX<0){l_diffsum-=l_diffX;}else{l_diffsum+=l_diffX;}
                        if(l_diffY<0){l_diffsum-=l_diffY;}else{l_diffsum+=l_diffY;}
                        int l_radius2 = (l_diffX*l_diffX)+(l_diffY*l_diffY);
                        if(l_radius2 < 10){l_radius2 = 10;}
                        double l_absA = 100000.0/l_radius2;
                        l_ax = l_ax + int(l_absA*l_diffX/l_diffsum);
                        l_ay = l_ay + int(l_absA*l_diffY/l_diffsum);
                    }
                }
                l_ax = l_ax%5;
                l_ay = l_ay%5;
                l_gb->setA(l_ax,l_ay);
            }
            for (int i = 0; i < l_count; ++i) {
                l_GBalls->at(i)->move();
            }
        }
    }
}

void GravityEngine::stop()
{
    this->stopFlag = true;
}
