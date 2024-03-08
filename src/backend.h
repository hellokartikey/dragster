#ifndef DRAGSTER_BACKEND_H
#define DRAGSTER_BACKEND_H

#include <QObject>

#include "mime.h"

class Backend : public QObject {
 private:
  Q_OBJECT;

  Q_PROPERTY(Mime* mime READ mimeType CONSTANT);
  Q_PROPERTY(MimeList mimes READ mimeList CONSTANT)

  Q_PROPERTY(qsizetype size READ size CONSTANT);

 public:
  explicit Backend(int argc, char* argv[], QObject* parent = nullptr);

  static auto inst(int argc, char* argv[]) -> Backend*;

  auto mimeType() -> Mime*;

  auto mimeList() const -> MimeList;

  auto size() const -> qsizetype;

 private:
  MimeList m_mime_types;
};

#endif
