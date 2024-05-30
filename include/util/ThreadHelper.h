#ifndef THREADHELPER_H
#define THREADHELPER_H

#include <functional>

class ThreadHelper {

public:
    static void runInMainThread(const std::function<void()> &func);

private:

};

#endif
