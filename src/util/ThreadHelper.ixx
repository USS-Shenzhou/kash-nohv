module;

#include <QApplication>
#include <QThread>
#include <qobject.h>

export module util.threadHelper;

export class ThreadHelper final : public QObject {
    Q_OBJECT

public:
    static void runInMainThread(const std::function<void()> &func) {
        if (QThread::currentThread() == QCoreApplication::instance()->thread()) {
            func();
        } else {
            QMetaObject::invokeMethod(&thiz, [func]() { func(); }, Qt::QueuedConnection);
        }
    }

private:
    static ThreadHelper thiz;
};

ThreadHelper ThreadHelper::thiz;
