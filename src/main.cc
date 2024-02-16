#include <QApplication>
#include <QtQml>
#include <QQuickStyle>
#include <QUrl>
#include <QDebug>

#include "mime.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    qCritical() << "Usage:\n\t" << argv[0] << "[FILE]";
    return 1;
  }

  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  auto app = QApplication(argc, argv);
  auto engine = QQmlApplicationEngine();

  auto mime_type = MimeTypeObject(argv[1]);

  engine.rootContext()->setContextProperty(
      "mime_icon",
      new MimeTypeObject(argv[1]));

  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  if (engine.rootObjects().isEmpty()) {
    return -1;
  }

  return app.exec();
}

