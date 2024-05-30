#include <QApplication>
#include <QCoreApplication>
#include <QThread>
#include <qobject.h>

#include "util/ThreadHelper.h"

void ThreadHelper::runInMainThread(const std::function<void()> &func) {
    if (QThread::currentThread() == QCoreApplication::instance()->thread()) {
        func();
    } else {
        QMetaObject::invokeMethod(QCoreApplication::instance(), [func]() { func(); }, Qt::QueuedConnection);
    }
}
