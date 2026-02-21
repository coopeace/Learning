#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <qobject.h>
#include <qtmetamacros.h>
#include <QTimer>

class StopWatch : public QObject {
  Q_OBJECT

  public:
    explicit StopWatch(QObject *parent = nullptr);

    void start();
    void stop();
    void reset();

  public slots:
    void updateTime();

  private:
    QTimer m_timer;
    int m_seconds;
};

#endif
