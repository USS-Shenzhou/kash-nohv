#include "../include/gui/window/kashnohv.h"
#include "../include/gui/window/loginsplashdialog.h"

#include <QApplication>

import oss;

int main(int argc, char *argv[]) {
    EndPoints::init();

    QApplication a(argc, argv);
    auto login = new LoginSplashDialog;
    if (login->exec() == QDialog::Accepted) {
        Kashnohv mainWindow;
        mainWindow.show();
        return a.exec();
    }
    return 0;
}