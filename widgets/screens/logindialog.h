#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

class QNetAccessManager;
class QNetworkReply;

namespace Ui
{
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit LoginDialog(QWidget *parent = nullptr);
    virtual ~LoginDialog();
private slots:
    void on_okButton_clicked();
    void on_quitButton_clicked();
    void handleResponse(QNetworkReply *reply);
private:
    void init();
    void fetchLogin();

    Ui::LoginDialog *ui;
    QNetAccessManager *m_netAccessManager;
};

#endif // LOGINDIALOG_H
