#include <QCoreApplication>
#include <QTimer>
#include <QString>
#include "bot.h"

int main (int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    QString token = qEnvironmentVariable("TELEGRAM_TOKEN");
    if (token.isEmpty()) {
        qFatal("TELEGRAM_TOKEN not set in environment!");
    }

    // 1. Initialize Components
    TelegramClient client(token, &app);
    UpdateDispatcher dispatcher(&app);
    CommandRouter router(&client, &app);

    // 2. Wire the flow
    // Flow: updatesReceived -> UpdateDispatcher::onUpdatesReceived
    QObject::connect(&client, &TelegramClient::updatesReceived, 
                     &dispatcher, &UpdateDispatcher::onUpdatesReceived);

    // Flow: messageReceived -> CommandRouter::onMessageReceived
    QObject::connect(&dispatcher, &UpdateDispatcher::messageReceived, 
                     &router, &CommandRouter::onMessageReceived);

    // 3. Setup Polling Timer
    QTimer timer(&app);
    QObject::connect(&timer, &QTimer::timeout, [&client, &dispatcher]() {
        client.getUpdates(dispatcher.lastUpdateId());
    });

    // Start polling every 3 seconds
    timer.start(3000);
    
    // Immediate first update
    QTimer::singleShot(0, [&client, &dispatcher]() {
        client.getUpdates(dispatcher.lastUpdateId());
    });

    qInfo() << "Bot is running...";
    return app.exec();
}
