#include "../include/kashnohv.h"
#include "../include/loginsplashdialog.h"

#include <QApplication>

void initQt();

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto login = new LoginSplashDialog;
    if (login->exec() == QDialog::Accepted) {
        Kashnohv mainWindow;
        mainWindow.show();
        return a.exec();
    }
    return 0;
}