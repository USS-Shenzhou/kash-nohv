#include "kashnohv.h"
#include "./ui_kashnohv.h"

Kashnohv::Kashnohv(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::Kashnohv) {
    ui->setupUi(this);
}

Kashnohv::~Kashnohv() {
    delete ui;
}