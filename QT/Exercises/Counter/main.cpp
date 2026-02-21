#include <QCoreApplication>
#include <QDebug>
#include <qcoreapplication.h>
#include <QTimer>
#include "counter.h"

int main (int argc, char *argv[]) {
  QCoreApplication app(argc,argv);
  Counter counter1,counter2;
  QObject::connect(&counter1,&Counter::valueChanged,&counter2,&Counter::increment);
  QObject::connect(&counter2,&Counter::valueChanged,&counter1,&Counter::increment);

  // counter1.start();//my method
  QTimer::singleShot(1000,&counter1,&Counter::increment);
  
  return app.exec();
}
