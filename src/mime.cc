#include "mime.h"

MimeTypeObject::MimeTypeObject(QString name) : name(name) {
  mime_type = db.mimeTypeForFile(name);
}

QString MimeTypeObject::getFileName() {
  return name;
}

void MimeTypeObject::setFileName(QString name) {
  this->name = name;
  mime_type = db.mimeTypeForFile(name);

  emit signalIconName();
  emit signalFileName();
}

QString MimeTypeObject::getIconName() {
  return mime_type.iconName();
}

void MimeTypeObject::setIconName(QString name) {
  emit signalIconName();
}

#include "moc_mime.cpp"

