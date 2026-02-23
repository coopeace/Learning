#include <QCoreApplication>
#include "counter.h"

int main (int argc, char *argv[]) {
  QCoreApplication app(argc,argv);

  Counter counter;
  counter.startCounter();

  QObject::connect(&counter,&Counter::processUpdated,
      [](int prog,int timeLeft){
          qInfo() << "UPDATED:" << prog << "%" << timeLeft << "s";
      }
      );
  return app.exec();
}
