#include <QCoreApplication>
#include "temperature.h"
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    Temperature temp;
    QObject::connect(&temp,&Temperature::temperatureChanged,
        [](double value1,const QString&unit1,double value2, const QString &unit2)
        {
          qInfo().noquote().nospace()
            << QString::number(value1, 'f', 2) << "°" << unit1 
            << " to " 
            << QString::number(value2, 'f', 2) << "°" << unit2;
        }
        );

    
    temp.startMonitoring();
    
    return app.exec();
}
