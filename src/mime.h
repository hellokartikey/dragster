#ifndef DRAGSTER_MIME_H
#define DRAGSTER_MIME_H

#include <QFile>
#include <QFileInfo>
#include <QMimeDatabase>
#include <QObject>

#include <filesystem>
#include <string>

namespace fs = std::filesystem;

class MimeTypeObject : public QObject {
  Q_OBJECT;

  Q_PROPERTY(QString  icon_name
             READ     getIconName
             NOTIFY   signalIconName);

  Q_PROPERTY(QString  file_name
             READ     getFileName
             NOTIFY   signalFileName);

public:
    MimeTypeObject(QObject* parent = nullptr, const fs::path& name = {});
    ~MimeTypeObject() = default;

    QString getIconName() const;
    QString getFileName() const;

signals:
    void    signalIconName();
    void    signalFileName();

private:
    fs::path  path;
    QMimeType mime_type;
};

#endif

