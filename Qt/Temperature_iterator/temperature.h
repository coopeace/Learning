#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <QObject>
#include <QTimer>

class Temperature : public QObject {
  Q_OBJECT
  private:
    double m_celsius, m_fahrenheit;
    QTimer *m_timer = new QTimer(this);
  public:
    explicit Temperature(QObject *parent = nullptr);
    void temperatureInCelsius(double c);
    void temperatureInFahrenheit(double f);
    public slots:
      void setCelsius(double c);     
      void setFahrenheit(double f);
      void startMonitoring();
      void stopMonitoring();
      void onTimerTick();
signals:
    void temperatureChanged(double value1,const QString&unit1,double value2, const QString &unit2);
};

#endif //TEMPERATURE_H
