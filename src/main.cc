#include <QApplication>
#include <QQuickStyle>
#include <QUrl>
#include <QtQml>

#include "backend.h"
#include "mime.h"

int main(int argc, char* argv[]) {
  auto app = QGuiApplication(argc, argv);
  auto engine = QQmlApplicationEngine();

  engine.rootContext()->setContextProperty("backend",
                                           Backend::inst(argc, argv));

  const auto qml_main = QUrl(QStringLiteral("qrc:/main.qml"));
  engine.load(qml_main);

  if (engine.rootObjects().isEmpty()) {
    return -1;
  }

  return app.exec();
}
