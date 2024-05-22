#include "kashnohv.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Kashnohv w;
    w.show();
    return a.exec();
}
