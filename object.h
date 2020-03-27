#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>
#include <QDebug>
#include <QUuid>

class Object : public QObject
{
    Q_OBJECT
public:
    explicit Object(const QString & type, QObject *parent = nullptr);
    ~Object();

signals:

public slots:

protected:
    QUuid m_id;
    QString m_type;

};

#endif // OBJECT_H
