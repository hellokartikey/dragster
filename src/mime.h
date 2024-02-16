#ifndef DRAGSTER_MIME_H
#define DRAGSTER_MIME_H

#include <QObject>
#include <QMimeDatabase>

class MimeTypeObject : public QObject {
  Q_OBJECT;

  Q_PROPERTY(QString  icon_name
             READ     getIconName
             WRITE    setIconName
             NOTIFY   signalIconName);

  Q_PROPERTY(QString  file_name
             READ     getFileName
             WRITE    setFileName
             NOTIFY   signalFileName);

public:
    MimeTypeObject(QString name);
    ~MimeTypeObject() = default;

    QString getIconName();
    void    setIconName(QString name);

    QString getFileName();
    void    setFileName(QString name);

signals:
    void    signalIconName();
    void    signalFileName();

private:
    QString name;
    QMimeDatabase db;
    QMimeType mime_type;
};

#endif

