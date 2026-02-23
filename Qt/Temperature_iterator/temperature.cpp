#include <QDebug>
#include "temperature.h"

Temperature::Temperature(QObject *parent) 
  : QObject(parent), m_celsius(0), m_fahrenheit(0) {
    connect(m_timer, &QTimer::timeout, this, &Temperature::onTimerTick);
  }

void Temperature::onTimerTick() {
    m_celsius += 0.1;
    qInfo() << "Live temp:" << m_celsius << "°C";
    setCelsius(m_celsius);
}

void Temperature::startMonitoring() {
    m_timer->start(500);
}

void Temperature::stopMonitoring() {
    m_timer->stop();
}

void Temperature::setCelsius(double c) {
  m_celsius = c;
  m_fahrenheit = (9 * c / 5) + 32;
  emit temperatureChanged(m_celsius, "C",m_fahrenheit,"F");
}
void Temperature::setFahrenheit(double f) {
  m_fahrenheit = f;
  m_celsius = (5 * (f - 32)) / 9;
  emit temperatureChanged(m_fahrenheit, "F",m_celsius,"C");
}

void Temperature::temperatureInCelsius(double c) { setCelsius(c); }
void Temperature::temperatureInFahrenheit(double f) { setFahrenheit(f); }
