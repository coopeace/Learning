#include "receiver.h"

void Receiver::handleMessage(QString text)
{
  qInfo() << "Received:" << text ;
}
