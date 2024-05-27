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

    auto* tmp_mime = new Mime(file_path, qobject_cast<QObject*>(this));

    m_model.append(tmp_mime);

    QObject::connect(tmp_mime, &Mime::sigChecked, this,
                     &Backend::setMultipleSelected);
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

auto Backend::isMultipleSelected() const -> bool {
  for (const auto* mime : m_model) {
    if (mime->isChecked()) {
      return true;
    }
  }

  return false;
}

auto Backend::multiMimeData() const -> QStringList {
  auto returnList = QStringList{};

  for (const auto* mime : m_model) {
    if (mime->isChecked()) {
      returnList << mime->fileUri();
    }
  }

  return returnList;
}

auto Backend::setMultipleSelected() -> void { Q_EMIT sigMultipleSelected(); }

#include "moc_backend.cpp"
