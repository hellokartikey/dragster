#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QString>
#include <QUrl>

#include "backend.h"

int main(int argc, char* argv[]) {
  using namespace Qt::Literals::StringLiterals;

  auto app = QApplication{argc, argv};
  auto engine = QQmlApplicationEngine{};

  engine.rootContext()->setContextProperty(u"backend"_s, Backend::inst(app));

  const auto main_qml = QUrl(u"qrc:/main.qml"_s);
  engine.load(main_qml);

  if (engine.rootObjects().isEmpty()) {
    return -1;
  }

  return app.exec();
}
