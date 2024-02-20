#include "mime.h"

QMimeDatabase mime_db;

MimeTypeObject::MimeTypeObject(const fs::path& name) : path(name) {
  mime_type = mime_db.mimeTypeForFile( QString::fromStdString(name.native()) );
}

QString MimeTypeObject::getFileName() {
  return QString::fromStdString( path.filename().native() );
}

QString MimeTypeObject::getIconName() {
  return mime_type.iconName();
}

#include "moc_mime.cpp"

