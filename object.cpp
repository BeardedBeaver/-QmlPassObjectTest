#include "object.h"

Object::Object(const QString &type, QObject *parent) : QObject(parent)
{
    m_id = QUuid::createUuid();
    m_type = type;
    qDebug() << "Object created" << m_id << m_type;
}

Object::~Object()
{
    qDebug() << "Object destroyed" << m_id << m_type;
}
