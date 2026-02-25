#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QBitArray>
#include <QJsonDocument>
#include <QTimer>

int main (int argc, char *argv[]) {
  QCoreApplication app(argc,argv);

  QNetworkAccessManager *manager = new QNetworkAccessManager(&app);

  QUrl url("https://api.telegram.org/bot<api>/getUpdates");

  QNetworkRequest request(url);

  // QTimer *timer = new QTimer(&app);
  //
  // QTimer::connect(timer,&QTimer::timeout,[&](){
  // QNetworkReply *reply = manager->get(request); 
  //     });
  //
  // timer->start(5000);

  QTimer::singleShot(1000,[&](){
      QNetworkReply *reply = manager->get(request); 

      QObject::connect(reply,&QNetworkReply::finished,[reply](){
          QByteArray data = reply->readAll();
          QJsonDocument doc = QJsonDocument::fromJson(data);
          qInfo().noquote() << doc.toJson(QJsonDocument::Indented);

          reply->deleteLater();
          });

      });

  return app.exec();
}
