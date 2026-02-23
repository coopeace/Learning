#ifndef COUNTER_H
#define COUNTER_H

#include <QCoreApplication>
#include <QDebug>
#include <QTimer>
#include <qobject.h>

class Counter: public QObject{
  Q_OBJECT
  private:
    int m_seconds;
    int m_progress;
    int init_seconds;
    QTimer *m_timer = new QTimer(this);
  public:
    explicit Counter(QObject *parent = nullptr): QObject(parent),m_seconds(30),m_progress(0){
      connect(m_timer,&QTimer::timeout,this,&Counter::progressOn);
      init_seconds = m_seconds;
    }
    void startCounter(){
      m_timer->start(100);
    }
    void resetCounter(int newseconds){
      m_progress=0;
      m_seconds=newseconds;
      init_seconds=newseconds;
      m_timer->stop();
      m_timer->start(100);
    }
  public slots:
    void progressOn(){
      m_progress += 3;
      int progressPercent=(m_progress)/(init_seconds*0.3);
      if (m_progress%10==0 && m_seconds > 1) {
        m_seconds--;
        // qInfo() << "Progress:" << progressPercent << "%" << " " << m_seconds << "s";
        emit processUpdated(progressPercent,m_seconds);
      }
      if(m_seconds<=1){
        qInfo() << "Done at 100%";
        m_timer->stop();
      }
    }
  signals:
    void processUpdated(int prog,int timeLeft);
};

#endif // !COUNTER_H
