#ifndef OSSMANAGER_H
#define OSSMANAGER_H

extern "C" {
#include "oss_c_sdk/aos_http_io.h"
#include "oss_c_sdk/oss_api.h"
}

#include "gui/window/loginsplashdialog.h"

class OssManager {
public:
    static void loginFromUi(LoginSplashDialog &dialog);

    static void loginFromSaved();

    static void init() {
        //TODO not OK
        aos_http_io_initialize(nullptr, 0);
        aos_pool_create(&pool,nullptr);
        options = oss_request_options_create(pool);
        atexit(cleanup);
    }

    OssManager(const OssManager &) = delete;

    OssManager &operator=(const OssManager &) = delete;

private:
    static aos_pool_t *pool;
    static oss_request_options_t *options;
    OssManager() {
    }

    ~OssManager() {

    }

    static bool loginInternal(LoginSplashDialog &dialog, QPushButton &button, const QString &endpointUrl, const QString &id, const QString &accessKey);

    static void cleanup() {
        aos_pool_destroy(pool);
        aos_http_io_deinitialize();
    }
};

#endif
