#include "interfaces.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

QByteArray IUserViewModel::toJson() const
{
    return QString("{"
        "\"id\": %1,"
        "\"firstName\": \"%2\","
        "\"lastName\": \"%3\","
        "\"email\": \"%4\","
        "\"username\": \"%5\","
        "\"passwordHash\": \"%6\","
        "\"phoneNumber\": \"%7\","
        "\"birthdate\": \"%8\","
        "\"country\": \"%9\","
        "\"province\": \"%10\","
        "\"city\": \"%11\","
        "\"zipCode\": \"%12\","
        "\"type\": %13,"
        "\"lastModified\": \"%14\","
        "\"createdDate\": \"%15\","
        "\"isDeleted\": \"%16\""
    "}"
    ).arg(id)
     .arg(firstName)
     .arg(lastName)
     .arg(email)
     .arg(username)
     .arg(passwordHash)
     .arg(phoneNumber)
     .arg(birthdate)
     .arg(country)
     .arg(province)
     .arg(city)
     .arg(zipCode)
     .arg(type)
     .arg(lastModified)
     .arg(createdDate)
     .arg(isDeleted)
     .toLatin1();
}

void IUserViewModel::fromJson(const QByteArray &json)
{
    QJsonDocument doc = QJsonDocument::fromJson(json);
    QJsonObject user = doc.object();
    id = user["id"].toInt();
    firstName = user["firstName"].toString();
    lastName = user["lastName"].toString();
    email = user["email"].toString();
    username = user["username"].toString();
    passwordHash = user["passwordHash"].toString();
    phoneNumber = user["phoneNumber"].toString();
    birthdate = user["birthdate"].toString();
    country = user["country"].toString();
    province = user["province"].toString();
    city = user["city"].toString();
    zipCode = user["zipCode"].toString();
    type = user["type"].toInt();
    lastModified = user["lastModified"].toString();
    createdDate = user["createdDate"].toString();
    isDeleted = user["isDeleted"].toBool();
}

QByteArray SigninUserRequest::toJson() const
{
    return QString("{"
        "\"usernameOrEmail\": \"%1\","
        "\"password\": \"%2\""
    "}"
    ).arg(usernameOrEmail, password).toLatin1();
}

void SigninUserRequest::fromJson(const QByteArray &json)
{
    QJsonDocument doc = QJsonDocument::fromJson(json);
    QJsonObject dto = doc.object();
    usernameOrEmail = dto["usernameOrEmail"].toString();
    password = dto["password"].toString();
}
