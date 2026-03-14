#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QUrl>
#include <qcontainerfwd.h>
#include <qlogging.h>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QNetworkAccessManager manager;

    // QString urlString = argv[1]; 
    // qInfo() << urlString;
    // app.quit();
    QUrl url(argv[1]);  // change this
    QNetworkReply *reply = manager.get(QNetworkRequest(url));

    QObject::connect(reply, &QNetworkReply::finished, [&]() {

        if(reply->error() == QNetworkReply::NoError)
        {
            QFile file("download.mkv");  // change extension if needed
            if(file.open(QIODevice::WriteOnly))
            {
                file.write(reply->readAll());
                file.close();
                qInfo() << "Download Complete!";
            }
        }
        else
        {
            qInfo() << "Error:" << reply->errorString();
        }

        reply->deleteLater();
        app.quit();
    });

    return app.exec();
}
