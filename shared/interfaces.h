#ifndef INTERFACES_H
#define INTERFACES_H

#include <QString>

class IBase
{
public:
    virtual QByteArray toJson() const = 0;
    virtual void fromJson(const QByteArray &json) = 0;
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

    QByteArray toJson() const override;
    void fromJson(const QByteArray &json) override;
};

class SigninUserRequest : public IBase
{
public:
    QString usernameOrEmail;
    QString password;

    QByteArray toJson() const override;
    void fromJson(const QByteArray &json) override;
};

#endif // INTERFACES_H
