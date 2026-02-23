#include <QCoreApplication>
#include "temperature.h"
#include <QDebug>
#include <qlogging.h>

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    Temperature temp1;
    QObject::connect(&temp1,&Temperature::temperatureChanged,
        [](double value1,const QString&unit1,double value2, const QString &unit2)
        {
        // qInfo().noquote() << QString("%1°%2 to %3°%4").arg(value1).arg(unit1).arg(value2).arg(unit2);
          qInfo().noquote().nospace()
            << QString::number(value1, 'f', 2) << "°" << unit1 
            << " to " 
            << QString::number(value2, 'f', 2) << "°" << unit2;
        }
        );

    // Test: Set 105F on temp1 → updates both, propagates to temp2
    temp1.temperatureInFahrenheit(105.0);

    return app.exec();
}
