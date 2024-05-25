module;

#include "gui/window/loginsplashdialog.h"

export module oss.ossManager;

export class OssManager {
public:
    static bool login(LoginSplashDialog &dialog) {
        return false;
    }

    OssManager(const OssManager &) = delete;

    OssManager &operator=(const OssManager &) = delete;

private:
    OssManager() {

    }

    ~OssManager() {

    }
};
