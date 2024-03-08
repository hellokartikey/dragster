#ifndef DRAGSTER_BACKEND_H
#define DRAGSTER_BACKEND_H

#include <QObject>
#include <QVariant>

#include "mime.h"

class Backend : public QObject {
 private:
  Q_OBJECT;

  Q_PROPERTY(QVariant mimeModel READ mimeModel CONSTANT)
  Q_PROPERTY(qsizetype size READ size CONSTANT);

 public:
  explicit Backend(int argc, char* argv[], QObject* parent = nullptr);

  static auto inst(int argc, char* argv[]) -> Backend*;

  auto mimeModel() -> QVariant;

  auto size() const -> qsizetype;

 private:
  MimeList m_model;
};

#endif
