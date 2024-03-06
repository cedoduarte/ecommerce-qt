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
        Store::currentUser.fromJson(reply->readAll());
        accept();
        qDebug() << Store::currentUser.username;
    }
    else
    {
        QString errorString = QString::fromLatin1(reply->readAll());
        errorString = errorString.mid(18, errorString.indexOf("!") - 17);
        QMessageBox::critical(this, "Error", errorString);
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
