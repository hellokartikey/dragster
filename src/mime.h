#ifndef DRAGSTER_MIME_H
#define DRAGSTER_MIME_H

#include <QMimeType>
#include <QObject>
#include <filesystem>

namespace fs = std::filesystem;

class MimeType : public QObject {
  Q_OBJECT;

  Q_PROPERTY(QString icon_name READ iconName CONSTANT);

  Q_PROPERTY(QString file_name READ fileName CONSTANT);

  Q_PROPERTY(QString name READ mimeName CONSTANT);

  Q_PROPERTY(QString uri READ fileUri CONSTANT);

 public:
  MimeType(QObject* parent = nullptr);
  ~MimeType() = default;

  void setPath(const fs::path& name);

  QString iconName() const;
  QString fileName() const;
  QString mimeName() const;
  QString fileUri() const;

 private:
  fs::path path;
  QMimeType mime_type;
};

#endif
