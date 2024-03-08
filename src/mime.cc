#include "mime.h"

#include <QFile>
#include <QMimeDatabase>
#include <QUrl>
#include <filesystem>

QMimeDatabase mime_db;

Mime::Mime(const fs::path& name, QObject* parent) : QObject(parent) {
  setPath(name);
}

auto Mime::setPath(const fs::path& name) -> void {
  path = fs::canonical(name);

  mime_type = mime_db.mimeTypeForFile(QString::fromStdString(path.native()));
}

auto Mime::fileName() const -> QString {
  return QString::fromStdString(path.filename().native());
}

auto Mime::iconName() const -> QString { return mime_type.iconName(); }

auto Mime::mimeName() const -> QString { return mime_type.name(); }

auto Mime::fileUri() const -> QString {
  auto url = QUrl::fromLocalFile(QString::fromStdString(path.native()));
  return url.toDisplayString();
}

#include "moc_mime.cpp"
