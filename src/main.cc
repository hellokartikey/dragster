#include <QApplication>
#include <QtQml>
#include <QQuickStyle>
#include <QUrl>

#include <filesystem>
#include <string>

#include <fmt/core.h>
#include <fmt/std.h>

#include "mime.h"

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    fmt::print(stderr, "Usage:\n\t{} FILE [ FILE... ]\n", argv[0]);
    return 1;
  }

  auto file_path = fs::path{argv[1]};

  if ( not fs::exists(file_path) or not fs::is_regular_file(file_path) ) {
    fmt::print(
        stderr,
        "{}: file does not exists or is inaccessible: {}\n",
        argv[0],
        file_path
    );
    return 1;
  }

  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  auto app = QApplication(argc, argv);
  auto engine = QQmlApplicationEngine();

  auto mime_type = MimeTypeObject(file_path);

  engine.rootContext()->setContextProperty(
      "mime",
      new MimeTypeObject(file_path)
  );

  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  if (engine.rootObjects().isEmpty()) {
    return -1;
  }

  return app.exec();
}

