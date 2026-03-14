#ifndef BOT_H
#define BOT_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QUrlQuery>
#include <QDebug>

// --- TelegramClient ---
class TelegramClient : public QObject {
    Q_OBJECT
public:
    explicit TelegramClient(const QString& token, QObject* parent = nullptr)
        : QObject(parent), m_token(token), m_manager(new QNetworkAccessManager(this)) {}

    void getUpdates(int offset = 0) {
        QUrl url(QString("https://api.telegram.org/bot%1/getUpdates").arg(m_token));
        if (offset > 0) {
            QUrlQuery query;
            query.addQueryItem("offset", QString::number(offset + 1));
            url.setQuery(query);
        }

        QNetworkReply* reply = m_manager->get(QNetworkRequest(url));
        connect(reply, &QNetworkReply::finished, this, [this, reply]() {
            if (reply->error() == QNetworkReply::NoError) {
                emit updatesReceived(QJsonDocument::fromJson(reply->readAll()));
            } else {
                qWarning() << "Network Error:" << reply->errorString();
            }
            reply->deleteLater();
        });
    }

    void sendMessage(const QString& chatId, const QString& text) {
        QUrl url(QString("https://api.telegram.org/bot%1/sendMessage").arg(m_token));
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

        QUrlQuery params;
        params.addQueryItem("chat_id", chatId);
        params.addQueryItem("text", text);

        m_manager->post(request, params.toString(QUrl::FullyEncoded).toUtf8());
    }

signals:
    void updatesReceived(const QJsonDocument& doc);

private:
    QString m_token;
    QNetworkAccessManager* m_manager;
};

// --- UpdateDispatcher ---
class UpdateDispatcher : public QObject {
    Q_OBJECT
public:
    explicit UpdateDispatcher(QObject* parent = nullptr) : QObject(parent), m_lastUpdateId(0) {}

    int lastUpdateId() const { return m_lastUpdateId; }

public slots:
    void onUpdatesReceived(const QJsonDocument& doc) {
        QJsonObject root = doc.object();
        if (!root["ok"].toBool()) return;

        QJsonArray updates = root["result"].toArray();
        for (const QJsonValue& v : updates) {
            QJsonObject update = v.toObject();
            m_lastUpdateId = update["update_id"].toInt();

            if (update.contains("message")) {
                QJsonObject msg = update["message"].toObject();
                QString chatId = QString::number(msg["chat"].toObject()["id"].toVariant().toLongLong());
                QString text = msg["text"].toString();
                emit messageReceived(chatId, text);
            }
        }
    }

signals:
    void messageReceived(const QString& chatId, const QString& text);

private:
    int m_lastUpdateId;
};

// --- CommandRouter ---
class CommandRouter : public QObject {
    Q_OBJECT
public:
    explicit CommandRouter(TelegramClient* client, QObject* parent = nullptr)
        : QObject(parent), m_client(client) {}

public slots:
    void onMessageReceived(const QString& chatId, const QString& text) {
        qInfo() << "Processing command from" << chatId << ":" << text;

        if (text == "/start") {
            m_client->sendMessage(chatId, "Howdy! Bot is up.Try /ping");
        } else if (text == "/ping") {
            m_client->sendMessage(chatId, "Pong!");
        } else {
            m_client->sendMessage(chatId,text);
        }
    }

private:
    TelegramClient* m_client;
};

#endif // BOT_H
