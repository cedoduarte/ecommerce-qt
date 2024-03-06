#include "widgets/screens/mainwindow.h"
#include "widgets/screens/logindialog.h"
#include "shared/qnetlib/qnetaccessmanager.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setStyle("fusion");
    if (!QNetAccessManager::isOpenSslAvailable())
    {
        QMessageBox::critical(nullptr, "Error", "OpenSSL is not installed, contact the administrator!");
        return  0;
    }
    MainWindow *window = nullptr;
    LoginDialog loginDialog;
    if (loginDialog.exec() == QDialog::Accepted)
    {
        window = new MainWindow;
        window->show();
    }
    else
    {
        return 0;
    }
    int exitCode = app.exec();
    delete window;
    return exitCode;
}
