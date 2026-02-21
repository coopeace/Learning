#include <QCoreApplication>
#include <QDebug>
#include <qcoreapplication.h>
#include <qtimer.h>
#include "temperature.h"

int main (int argc, char *argv[]) {
  QCoreApplication app(argc,argv);
  Temperature temp1,temp2;
  QObject::connect(&temp1,&Temperature::temperatureChanged,&temp2,&Temperature::setCelcius);

  temp1.temperatureInFahrenheit(105);
  return app.exec();
}
