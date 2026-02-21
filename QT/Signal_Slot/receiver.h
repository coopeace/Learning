#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QDebug>

class Receiver : public QObject 
{
  Q_OBJECT

public slots:
  void handleMessage(QString text);
};

#endif
