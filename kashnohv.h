#ifndef KASHNOHV_H
#define KASHNOHV_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class Kashnohv;
}
QT_END_NAMESPACE

class Kashnohv : public QMainWindow {
Q_OBJECT

public:
    Kashnohv(QWidget *parent = nullptr);

    ~Kashnohv();

private:
    Ui::Kashnohv *ui;
};

#endif // KASHNOHV_H
