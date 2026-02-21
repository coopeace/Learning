#include "sender.h"

Sender::Sender(QObject *parent) : QObject(parent)
{
}

void Sender::doSomething()
{
  emit messageReady("Hello form Sender!");
}
