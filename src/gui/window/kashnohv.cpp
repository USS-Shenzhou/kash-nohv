#include "gui/window/kashnohv.h"

Kashnohv::Kashnohv(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::Kashnohv) {
    ui->setupUi(this);
    setWindowTitle("Kash-nohv");
    setWindowIcon(QIcon(":/textures/logo.png"));
}

Kashnohv::~Kashnohv() {
    delete ui;
}
