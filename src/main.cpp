#include "gui/window/kashnohv.h"
#include "gui/window/loginsplashdialog.h"

#include <QApplication>

#include "oss/EndPoints.h"
#include "oss/OssManager.h"

int main(int argc, char *argv[]) {
    EndPoints::init();
    OssManager::init();

    QApplication a(argc, argv);
    auto login = new LoginSplashDialog;
    if (login->exec() == QDialog::Accepted) {
        Kashnohv mainWindow;
        mainWindow.show();
        return a.exec();
    }
    return 0;
}