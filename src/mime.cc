#include "mime.h"

QMimeDatabase mime_db;

MimeTypeObject::MimeTypeObject(QObject* parent, const fs::path& name)
    : path(name)
    , QObject(parent) {
  mime_type = mime_db.mimeTypeForFile( QString::fromStdString(name.native()) );
}

QString MimeTypeObject::getFileName() const {
  return QString::fromStdString( path.filename().native() );
}

QString MimeTypeObject::getIconName() const {
  return mime_type.iconName();
}

#include "moc_mime.cpp"

