#ifndef DRAGSTER_BACKEND_H
#define DRAGSTER_BACKEND_H

#include <QCoreApplication>
#include <QObject>
#include <QVariant>

#include "mime.h"

class Backend : public QObject {
 private:
  Q_OBJECT;

  Q_PROPERTY(MimeList mimeModel READ mimeModel CONSTANT)
  Q_PROPERTY(qsizetype size READ size CONSTANT);

 public:
  explicit Backend(const QCoreApplication& app, QObject* parent = nullptr);

  static auto inst(const QCoreApplication& app) -> Backend*;

  auto mimeModel() -> MimeList;

  auto size() const -> qsizetype;

 private:
  MimeList m_model;
};

#endif
