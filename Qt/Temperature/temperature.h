#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <QObject>
#include <QString>

class Temperature : public QObject {
    Q_OBJECT
public:
    explicit Temperature(QObject *parent = nullptr) : QObject(parent), m_celsius(0), m_fahrenheit(0) {}

    double celsius() const { return m_celsius; }
    double fahrenheit() const { return m_fahrenheit; }

public slots:
    void setCelsius(double c) {
        m_celsius = c;
        m_fahrenheit = (9 * c / 5) + 32;
        emit temperatureChanged(m_celsius, "C",m_fahrenheit,"F");
    }
    void setFahrenheit(double f) {
        m_fahrenheit = f;
        m_celsius = (5 * (f - 32)) / 9;
        emit temperatureChanged(m_fahrenheit, "F",m_celsius,"C");
    }
    void temperatureInCelsius(double c) { setCelsius(c); }
    void temperatureInFahrenheit(double f) { setFahrenheit(f); }

signals:
    void temperatureChanged(double value1,const QString&unit1,double value2, const QString &unit2);

private:
    double m_celsius;
    double m_fahrenheit;
};
#endif // TEMPERATURE_H
