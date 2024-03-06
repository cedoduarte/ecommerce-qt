#include "qnetaccessmanager.h"

QNetAccessManager::QNetAccessManager(QObject *parent)
    : QNetworkAccessManager(parent)
{
}

QNetAccessManager::~QNetAccessManager()
{
}

QNetworkReply *QNetAccessManager::patch(const QNetRequest &request, QIODevice *data)
{
    return sendCustomRequest(request, "PATCH", data);
}

QNetworkReply *QNetAccessManager::patch(const QNetRequest &request, const QByteArray &data)
{
    return sendCustomRequest(request, "PATCH", data);
}

QNetworkReply *QNetAccessManager::patch(const QNetRequest &request, QHttpMultiPart *multiPart)
{
    return sendCustomRequest(request, "PATCH", multiPart);
}
