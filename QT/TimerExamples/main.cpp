#include <QCoreApplication>
#include <QTimer>
#include <QDebug>

int main (int argc, char *argv[]) {
  QCoreApplication app(argc,argv);
  QTimer timer;

  // QObject::connect(&timer,&QTimer::timeout,[&]()
  //     {
  //       qInfo() << "Boom";
  //       app.quit();
  //     });
  QTimer::singleShot(3000,[](){
      qInfo() << "Boom";
      });

  return app.exec();
}
