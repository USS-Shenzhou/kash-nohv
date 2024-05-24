#include "../include/loginsplashdialog.h"
#include "../ui_loginsplashdialog.h"

using namespace AlibabaCloud::OSS;

LoginSplashDialog::LoginSplashDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginSplashDialog)
{
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowTitle("Kash-nohv");
    setWindowIcon(QIcon(":/textures/logo.png"));

    connect(ui->loginButton, SIGNAL(clicked(bool)),this, SLOT(doLogin()));
}

LoginSplashDialog::~LoginSplashDialog()
{
    delete ui;
}

void LoginSplashDialog::doLogin() {
    ui->loginButton->setEnabled(false);
    ui->loginButton->setText("正在连接到服务器...");

    accept();
}
