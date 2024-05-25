#ifndef LOGINSPLASHDIALOG_H
#define LOGINSPLASHDIALOG_H

#include <QDialog>

namespace Ui {
    class LoginSplashDialog;
}

class LoginSplashDialog : public QDialog {
Q_OBJECT

public:
    explicit LoginSplashDialog(QWidget *parent = nullptr);

    ~LoginSplashDialog();

    Ui::LoginSplashDialog &getUi() {
        return *ui;
    }

private slots:

    void doLogin();

private:
    Ui::LoginSplashDialog *ui;
};

#endif // LOGINSPLASHDIALOG_H
