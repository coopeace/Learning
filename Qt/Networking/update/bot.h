#ifndef BOT_H
#define BOT_H

#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrlQuery>
#include <QDebug>
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

class Bot : public QObject {
  Q_OBJECT;
public:

explicit Bot(QString token,QObject *parent = nullptr) : QObject(parent),m_token(token)
  {
    manager = new QNetworkAccessManager(this);
  }

void getUpdates(){
    QNetworkRequest request(QUrl (QString("https://api.telegram.org/bot%1/getUpdates").arg(m_token)));
    QNetworkReply *reply = manager->get(request);
    connect(reply,&QNetworkReply::finished,[reply, this](){
    if (reply->error() == QNetworkReply::NoError) {

        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        QJsonObject json = doc.object();
        QJsonArray result = json["result"].toArray();
        for( QJsonValue v : result){
          QJsonObject update = v.toObject();
            qInfo().noquote() << "update_id:" << v["update_id"].toInt();
        }
        
        emit updateReceived();
    }
    else {
      qWarning() << "Error:" << reply->readAll();
    }
    reply->deleteLater();
    });
}
  
signals:
  void updateReceived();

public slots:

private:
  QNetworkAccessManager *manager;
  QString m_token;
};


#endif // !BOT_H
