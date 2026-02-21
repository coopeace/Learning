#include <QCoreApplication>
#include "sender.h"
#include "receiver.h"

int main (int argc, char *argv[]) {
  QCoreApplication app(argc, argv);

  Sender sender;
  Receiver receiver;

  QObject::connect(&sender,&Sender::messageReady,
      &receiver, &Receiver::handleMessage);

  sender.doSomething();

  return app.exec();
}
