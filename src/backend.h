#ifndef DRAGSTER_BACKEND_H
#define DRAGSTER_BACKEND_H

#include <QApplication>
#include <QObject>

#include "mime.h"

class Backend : public QObject {
 private:
  Q_OBJECT

  Q_PROPERTY(MimeList mimeModel READ mimeModel CONSTANT)
  Q_PROPERTY(qsizetype size READ size CONSTANT)
  Q_PROPERTY(bool isMultipleSelected READ isMultipleSelected NOTIFY
                 sigMultipleSelected)
  Q_PROPERTY(
      QStringList multiMimeData READ multiMimeData NOTIFY sigMultiMimeData)

 public:
  explicit Backend(const QApplication& app, QObject* parent = nullptr);

  static auto inst(const QApplication& app) -> Backend*;

  auto mimeModel() -> MimeList;

  auto size() const -> qsizetype;

  auto isMultipleSelected() const -> bool;
  auto setMultipleSelected() -> void;

  auto multiMimeData() const -> QStringList;

 Q_SIGNALS:
  void sigMultipleSelected();
  void sigMultiMimeData();

 private:
  MimeList m_model;
};

#endif
