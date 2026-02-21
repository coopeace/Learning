#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QCoreApplication>

class Temperature : public QObject{
  Q_OBJECT
  public:
    explicit Temperature(QObject *parent = nullptr) : QObject(parent),m_celcius(0),m_fahrenheit(0){
      connect(m_timer,&QTimer::timeout,this,&Temperature::ticking);
    }
    void temperatureInCelcius(double c) { return setCelcius(c);}
    void temperatureInFahrenheit(double f){ return setFahrenheit(f);}
    double celcius() { return m_celcius; }
    double fahrenheit() { return m_fahrenheit; }

  private:
    double m_celcius;
    double m_fahrenheit;

    QTimer *m_timer = new QTimer(this);
  public slots:
    void setCelcius(double c){
      m_celcius = c;
      m_fahrenheit = ((9*c)/5) + 32;
      qInfo() << "Set celcius:" << m_celcius << "Conversion in fahrenheit:" << m_fahrenheit; 
      emit temperatureChanged(m_fahrenheit,"fahrenheit");

    }
    void setFahrenheit(double f){
      m_fahrenheit = f;
      m_celcius = (5*(f - 32))/9;
      qInfo() << "Set fahrenheit:" << m_fahrenheit << "Conversion in celcius:" << m_celcius; 
      emit temperatureChanged(m_celcius,"celcius");

    };

    void startMonitoring(){
      m_timer->start(500);
    }
    void stopMonitoring(){
      m_timer->stop();
    }
    void ticking(){
      m_celcius += 0.1;
      qInfo() << "Live Temp:" << m_celcius << " °C";
      setCelcius(m_celcius);
    }
  signals:
    void temperatureChanged(double, QString unit);
};
#endif // !TEMPERATURE_H
