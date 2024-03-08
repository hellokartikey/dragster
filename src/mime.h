#ifndef DRAGSTER_MIME_H
#define DRAGSTER_MIME_H

#include <QList>
#include <QMimeType>
#include <QObject>
#include <filesystem>

namespace fs = std::filesystem;

class Mime : public QObject {
  Q_OBJECT;

  Q_PROPERTY(QString icon_name READ iconName CONSTANT);

  Q_PROPERTY(QString file_name READ fileName CONSTANT);

  Q_PROPERTY(QString name READ mimeName CONSTANT);

  Q_PROPERTY(QString uri READ fileUri CONSTANT);

 public:
  explicit Mime(const fs::path& name, QObject* parent = nullptr);
  ~Mime() = default;

  auto setPath(const fs::path& name) -> void;

  auto iconName() const -> QString;
  auto fileName() const -> QString;
  auto mimeName() const -> QString;
  auto fileUri() const -> QString;

 private:
  fs::path path;
  QMimeType mime_type;
};

using MimeList = QList<Mime*>;

#endif
