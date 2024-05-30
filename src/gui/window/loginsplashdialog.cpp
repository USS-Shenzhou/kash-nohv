#include "gui/window/loginsplashdialog.h"

#include "oss/EndPoints.h"
#include "oss/OssManager.h"


LoginSplashDialog::LoginSplashDialog(QWidget *parent) :
    QDialog(parent), ui(new Ui::LoginSplashDialog) {
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle("Kash-nohv");
    setWindowIcon(QIcon(":/textures/logo.png"));

    setFixedSize(800, 450);

    ui->endpointSelect->addItems(EndPoints::getNameAndUrl().keys());
    ui->endpointSelect->setCurrentIndex(-1);

    connect(ui->loginButton, SIGNAL(clicked(bool)), this, SLOT(doLogin()));
}

LoginSplashDialog::~LoginSplashDialog() {
    delete ui;
}

void LoginSplashDialog::doLogin() {
    if (ui->endpointSelect->currentIndex() > -1 && !ui->account->text().isEmpty() && !ui->password->text().isEmpty()) {
        OssManager::loginFromUi(*this);
    }
}
