#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QString>

class Constants
{
public:
    Constants() = delete;

    static const QString AUTHORIZATION_TOKEN;

    static const QString API_BASE_URL;

    static const QString URL_USER_CHANGE_PASSWORD;
    static const QString URL_USER_CREATE;
    static const QString URL_USER_DELETE;
    static const QString URL_ACCOUNT_DELETE;
    static const QString URL_USER_RESTORE;
    static const QString URL_USER_SIGNIN;
    static const QString URL_USER_UPDATE;
    static const QString URL_USER_GET_BY_ID;
    static const QString URL_USER_GET_LIST;
    static const QString URL_PRODUCT_CREATE;
    static const QString URL_PRODUCT_DELETE;
    static const QString URL_PRODUCT_RESTORE;
    static const QString URL_PRODUCT_UPDATE;
    static const QString URL_PRODUCT_GET_BY_ID;
    static const QString URL_PRODUCT_GET_LIST;

    static const std::vector<QString> COUNTRY_LIST;
};

#endif // CONSTANTS_H
