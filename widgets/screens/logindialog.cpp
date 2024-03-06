#include "logindialog.h"
#include "ui_logindialog.h"
#include "../../shared/qnetlib/qnetaccessmanager.h"
#include "../../shared/constants.h"
#include "../../shared/interfaces.h"
#include "../../shared/store.h"

#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    init();
}

void LoginDialog::init()
{
    m_netAccessManager = new QNetAccessManager(this);
    connect(m_netAccessManager, &QNetAccessManager::finished, this, &LoginDialog::handleResponse);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_okButton_clicked()
{
    fetchLogin();
}

void LoginDialog::on_quitButton_clicked()
{
    close();
}

void LoginDialog::handleResponse(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
        QJsonObject user = doc.object();
        Store::currentUser.id = user["id"].toInt();
        Store::currentUser.firstName = user["firstName"].toString();
        Store::currentUser.lastName = user["lastName"].toString();
        Store::currentUser.email = user["email"].toString();
        Store::currentUser.username = user["username"].toString();
        Store::currentUser.passwordHash = user["passwordHash"].toString();
        Store::currentUser.phoneNumber = user["phoneNumber"].toString();
        Store::currentUser.birthdate = user["birthdate"].toString();
        Store::currentUser.country = user["country"].toString();
        Store::currentUser.province = user["province"].toString();
        Store::currentUser.city = user["city"].toString();
        Store::currentUser.zipCode = user["zipCode"].toString();
        Store::currentUser.type = user["type"].toInt();
        Store::currentUser.lastModified = user["lastModified"].toString();
        Store::currentUser.createdDate = user["createdDate"].toString();
        Store::currentUser.isDeleted = user["isDeleted"].toBool();
        accept();
        qDebug() << Store::currentUser.username;
    }
    else
    {
        QString errorString = QString::fromLatin1(reply->readAll());
        QMessageBox::critical(this, "Error", errorString.mid(18, errorString.indexOf("!") + 1));
    }
}

void LoginDialog::fetchLogin()
{
    QNetRequest request;
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Authorization", Constants::AUTHORIZATION_TOKEN.toLatin1());
    request.setUrl(QUrl(Constants::URL_USER_SIGNIN));
    SigninUserRequest requestBody;
    requestBody.usernameOrEmail = ui->txtUsername->text();
    requestBody.password = ui->txtPassword->text();
    m_netAccessManager->post(request, requestBody.toJson());
}
