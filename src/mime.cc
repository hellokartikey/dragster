#include "mime.h"

#include <QFile>
#include <QIcon>
#include <QMimeDatabase>
#include <QUrl>
#include <filesystem>

QMimeDatabase mime_db;

Mime::Mime(const fs::path& name, QObject* parent)
    : QObject(parent), checked(false) {
  setPath(name);
}

auto Mime::setPath(const fs::path& name) -> void {
  path = fs::canonical(name);

  mime_type = mime_db.mimeTypeForFile(QString::fromStdString(path.native()));
}

auto Mime::fileName() const -> QString {
  return QString::fromStdString(path.filename().native());
}

auto Mime::iconName() const -> QString {
  using namespace Qt::Literals::StringLiterals;

  auto fallback = QIcon::fromTheme(u"unknown"_s);
  return QIcon::fromTheme(mime_type.iconName(), fallback).name();
}

auto Mime::mimeName() const -> QString { return mime_type.name(); }

auto Mime::fileUri() const -> QString {
  auto url = QUrl::fromLocalFile(QString::fromStdString(path.native()));
  return url.toDisplayString();
}

auto Mime::isChecked() const -> bool { return checked; }

auto Mime::setChecked(bool checked) -> void {
  if (this->checked == checked) return;
  this->checked = checked;
  Q_EMIT sigChecked();
}

#include "moc_mime.cpp"
