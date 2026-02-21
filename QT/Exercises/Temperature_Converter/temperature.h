#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <qtimer.h>

class Temperature : public QObject{
  Q_OBJECT
  public:
    explicit Temperature(QObject *parent = nullptr);
    void temperatureInCelcius(double);
    void temperatureInFahrenheit(double);

  private:
    double m_celcius;
    double m_fahrenheit;
  public slots:
    void setCelcius(double);
    void setFahrenheit(double);
  signals:
    void temperatureChanged(double, QString unit);
};
#endif // !TEMPERATURE_H
