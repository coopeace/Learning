#include <QCoreApplication>
#include "temperature.h"

int main (int argc, char *argv[]) {
  QCoreApplication app(argc,argv);
  Temperature temp;

  temp.startMonitoring();
  return app.exec();
}
