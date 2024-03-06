#ifndef INTERFACES_H
#define INTERFACES_H

#include <QString>

class IBase
{
public:
    virtual QByteArray toJson() const = 0;
};

class IUserViewModel : public IBase
{
public:
    int id;
    QString firstName;
    QString lastName;
    QString email;
    QString username;
    QString passwordHash;
    QString phoneNumber;
    QString birthdate;
    QString country;
    QString province;
    QString city;
    QString zipCode;
    int type;
    QString lastModified;
    QString createdDate;
    bool isDeleted;

    QByteArray toJson() const override
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
};

class SigninUserRequest : public IBase
{
public:
    QString usernameOrEmail;
    QString password;

    QByteArray toJson() const override
    {
        return QString("{"
            "\"usernameOrEmail\": \"%1\","
            "\"password\": \"%2\""
        "}"
        ).arg(usernameOrEmail, password).toLatin1();
    }
};

#endif // INTERFACES_H
