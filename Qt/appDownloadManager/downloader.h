#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QString>
#include <QUrl>
#include <QNetworkRequest>
#include <QStandardPaths>
#include <QDateTime>
#include <QDir>
#include <QDebug>

class Downloader : public QObject {
    Q_OBJECT
    Q_PROPERTY(double progress READ progress NOTIFY progressChanged)
    Q_PROPERTY(QString lastSavedPath READ lastSavedPath NOTIFY lastSavedPathChanged)

public:
    explicit Downloader(QObject *parent = nullptr) : QObject(parent) {
        manager = new QNetworkAccessManager(this);
    }

    Q_INVOKABLE void startDownload(const QString &urlStr) {
        m_progress = 0;
        emit progressChanged();
        
        QUrl url(urlStr);
        if (!url.isValid()) {
            qWarning() << "Invalid URL:" << urlStr;
            return;
        }

        reply = manager->get(QNetworkRequest(url));

        connect(reply, &QNetworkReply::downloadProgress,
                this, &Downloader::onProgress);

        connect(reply, &QNetworkReply::finished,
                this, &Downloader::onFinished);
    }

    double progress() const { return m_progress; }
    QString lastSavedPath() const { return m_lastSavedPath; }

signals:
    void progressChanged();
    void finished();
    void lastSavedPathChanged();

private slots:
    void onProgress(qint64 received, qint64 total) {
        if (total > 0) {
            m_progress = (double)received / total;
            emit progressChanged();
        }
    }

    void onFinished() {
        if (reply && reply->error() == QNetworkReply::NoError) {
            QString downloadPath = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
            if (downloadPath.isEmpty()) {
                downloadPath = QDir::currentPath();
            }
            
            QDir dir(downloadPath);
            if (!dir.exists()) {
                dir.mkpath(".");
            }

            QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd_HH-mm-ss");
            QUrl url = reply->url();
            QString fileName = url.fileName();
            if (fileName.isEmpty()) {
                fileName = "download";
            }
            
            m_lastSavedPath = downloadPath + "/" + timestamp + "_" + fileName;
            
            QFile file(m_lastSavedPath);
            if (file.open(QIODevice::WriteOnly)) {
                file.write(reply->readAll());
                file.close();
                emit lastSavedPathChanged();
            } else {
                qWarning() << "Could not open file for writing:" << m_lastSavedPath;
            }
        } else if (reply) {
            qWarning() << "Download failed:" << reply->errorString();
        }

        emit finished();
        if (reply) {
            reply->deleteLater();
            reply = nullptr;
        }
    }

private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply = nullptr;
    double m_progress = 0;
    QString m_lastSavedPath;
};

#endif
