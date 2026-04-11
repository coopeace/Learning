#ifndef BOT_H
#define BOT_H

#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QDebug>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QString>
#include <qtenvironmentvariables.h>

class Updates : public QObject {
  Q_OBJECT;
public:
  QString token = qEnvironmentVariable("TELEGRAM_TOKEN");
  explicit Updates(QObject *parent = nullptr): m_updateId(0){
    QNetworkAccessManager *manager = new QNetworkAccessManager(this); 
  }
  void getUpdates(){
    QUrl url(QString("https://api.telegram.org/bot%1/getUpdates").arg(token));
    
  }
  
signals:
  void updateReceived(int updateId,QString const text);

public slots:

private:
  int m_updateId;
};


#endif // !
