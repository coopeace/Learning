#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

int main (int argc, char *argv[]) {
  QCoreApplication app(argc,argv);
  QNetworkAccessManager *manager = new QNetworkAccessManager(&app);
  
  QUrl url("https://api.github.com/users/octocat");
  QNetworkRequest request(url);
  QNetworkReply *reply = manager->get(request);
  QObject::connect(reply,&QNetworkReply::finished,[&](){
      if(reply->error()==QNetworkReply::NoError){
        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        // qInfo().noquote() << doc.toJson(QJsonDocument::Indented);
        if(doc.isObject()){
          QJsonObject obj = doc.object();
          qInfo().noquote() << "Username:" << obj["login"].toString();
          qInfo() << "Followers:" << obj["followers"].toInt();
          qInfo() << "Public repos:" << obj["public_repos"].toInt();
        }

      }
      else{
        qInfo() << "Error:" << reply->errorString();
      }
      reply->deleteLater();
      });
  return app.exec();
}
