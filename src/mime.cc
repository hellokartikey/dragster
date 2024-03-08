#include "mime.h"

#include <QMimeDatabase>
#include <QFile>

#include <filesystem>

QMimeDatabase mime_db;

MimeType::MimeType(QObject* parent) : QObject(parent) {}

void MimeType::setPath(const fs::path& name) {
  path = fs::canonical(name);

  mime_type = mime_db.mimeTypeForFile(QString::fromStdString(path.native()));
}

QString MimeType::fileName() const {
  return QString::fromStdString(path.filename().native());
}

QString MimeType::iconName() const {
  return mime_type.iconName();
}

QString MimeType::mimeName() const {
  return mime_type.name();
}

QString MimeType::fileUri() const {
  return QString::fromStdString("file://" + path.native());
}

#include "moc_mime.cpp"

