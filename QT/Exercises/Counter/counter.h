#ifndef COUNTER_H
#define COUNTER_H

#include <QCoreApplication>
#include <QDebug>
#include <qlogging.h>

class Counter : public QObject{
  Q_OBJECT
  public:
    explicit Counter(QObject *parent = nullptr) : QObject(parent),m_value(0) {}
    // void start(){
    //   emit valueChanged();
    // }
  public slots:
    void increment(){
      m_value++;
      qInfo() << m_value;
      emit valueChanged();
    }
  signals:
    void valueChanged();
  private:
    int m_value;
};

#endif // !COUNTER
