#include "temperature.h"
#include <QDebug>

Temperature::Temperature(QObject *parent) :
  QObject(parent),m_celcius(0),m_fahrenheit(0)
{
}

void Temperature::setFahrenheit(double f){
  m_fahrenheit = f;
  m_celcius = (5*(f - 32))/9;
  qInfo() << "Set fahrenheit:" << m_fahrenheit << "Conversion in celcius:" << m_celcius; 
  emit temperatureChanged(m_celcius," degree celcius.");
}

void Temperature::setCelcius(double c){
  m_celcius = c;
  m_fahrenheit = ((9*c)/5) + 32;
  qInfo() << "Set celcius:" << m_celcius << "Conversion in fahrenheit:" << m_fahrenheit; 
  emit temperatureChanged(m_fahrenheit," degree fahrenheit.");
}

void Temperature::temperatureInCelcius(double c){
  setCelcius(c);
}

void Temperature::temperatureInFahrenheit(double f){
  setFahrenheit(f);
}
