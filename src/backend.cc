#include "backend.h"

#include <fmt/core.h>
#include <fmt/std.h>

#include <QTimer>
#include <chrono>

#include "mime.h"
#include "version.h"

Backend::Backend(const QApplication& app, QObject* parent) : QObject(parent) {
  using namespace std::literals::chrono_literals;

  auto argv = app.arguments();
  auto argc = argv.size();

  auto name = argv[0].toStdString();

  for (qsizetype idx = 1; idx < argc; idx++) {
    auto file_path = fs::path{argv[idx].toStdString()};

    if (!fs::exists(file_path)) {
      fmt::print(stderr, "{}: file does not exists or is inaccessible: {}\n",
                 name, file_path);
      continue;
    }

    m_model.append(new Mime(file_path, qobject_cast<QObject*>(this)));
  }

  if (m_model.size() < 1) {
    fmt::print(stderr, "version: {}\n", DRAGSTER_VERSION_STRING);
    fmt::print(stderr, "Usage:\n\t{} [FILE...]\n", name);
    QTimer::singleShot(0ms, [&]() { app.exit(1); });
    return;
  }
}

auto Backend::inst(const QApplication& app) -> Backend* {
  static Backend backend(app);

  return &backend;
}

auto Backend::mimeModel() -> MimeList { return m_model; }

auto Backend::size() const -> qsizetype { return m_model.size(); }

#include "moc_backend.cpp"
