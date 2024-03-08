#ifndef DRAGSTER_BACKEND_H
#define DRAGSTER_BACKEND_H

#include <QObject>

#include "mime.h"

class Backend : public QObject {
private:
  Q_OBJECT;

  Q_PROPERTY(MimeType* mime
             READ      mimeType
             CONSTANT);

public:
  explicit Backend(QObject* parent=nullptr);

  static Backend* inst(int argc, char* argv[]);

  MimeType* mimeType();

private:
  MimeType m_mime_type;
};

#endif

