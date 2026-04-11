#include <QCoreApplication>
#include <QTimer>
#include <qnetworkreply.h>
#include "bot.h"

int main (int argc, char *argv[]) {
  QString token = qEnvironmentVariable("TELEGRAM_TOKEN");
  QCoreApplication app(argc,argv);
  Bot bot(token,&app);
  QTimer::singleShot(0,[&bot]()
      {
      bot.getUpdates();
      });
  return app.exec();
}
