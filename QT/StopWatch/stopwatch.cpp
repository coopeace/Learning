#include "stopwatch.h"
#include <qobject.h>
#include <iostream>

StopWatch::StopWatch(QObject *parent) : QObject(parent),m_seconds(0) {}

void StopWatch::start(){
  m_timer.start(1000);
}

void StopWatch::stop(){
  m_timer.stop();
}

void StopWatch::reset(){
  m_seconds = 0;
}

void StopWatch::updateTime(){
  m_seconds++;
  int minutes = m_seconds/60;
  int seconds = m_seconds%60;

  std::cout << '\t' << minutes << ":" << seconds << std::endl;
}
  
