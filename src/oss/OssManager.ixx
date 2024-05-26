module;

#include <QtConcurrent/QtConcurrent>
#include <alibabacloud/oss/OssClient.h>
#include <ui_loginsplashdialog.h>
#include "gui/window/loginsplashdialog.h"

import util.threadHelper;
import oss.endpoints;

export module oss.ossManager;

export class OssManager {
public:
    static void loginFromUi(LoginSplashDialog &dialog) {
        const auto ui = dialog.getUi();
        auto result = QtConcurrent::run([&]() -> bool {
            return loginInternal(dialog, *ui.loginButton, EndPoints::getnameAndUrl().value(ui.endpointSelect->currentText()), ui.account->text(), ui.password->text());
        });
        result.then([](bool b) -> void {
            //TODO save
        });
    }

    static void loginFromSaved() {
        // TODO
    }

    OssManager(const OssManager &) = delete;

    OssManager &operator=(const OssManager &) = delete;

private:
    static AlibabaCloud::OSS::OssClient *ossClient;
    OssManager() {
    }

    ~OssManager() {
        AlibabaCloud::OSS::ShutdownSdk();
        delete ossClient;
    }

    static bool loginInternal(LoginSplashDialog &dialog, QPushButton &button, const QString &endpointUrl, const QString &id, const QString &accessKey) {
        ThreadHelper::runInMainThread([&]() -> void {
            button.setEnabled(false);
            button.setText("正在连接到服务器...");
        });
        {
            using namespace AlibabaCloud::OSS;
            InitializeSdk();
            ClientConfiguration clientConfig;
            clientConfig.signatureVersion = SignatureVersionType::V4;
            // TODO speed limit by config
            ossClient = new OssClient(endpointUrl.toStdString(), id.toStdString(), accessKey.toStdString(), clientConfig);
            ListBucketsRequest request;
            auto result = ossClient->ListBuckets(request);
            if (result.isSuccess()) {
                ThreadHelper::runInMainThread([&]() -> void {
                    dialog.accept();
                });
                return true;
            } else {
                ThreadHelper::runInMainThread([&]() -> void {
                    button.setEnabled(true);
                    button.setText(QString::fromStdString(result.error().Code()) + " 请重试。");
                });
                return false;
            }
        }
    }
};

AlibabaCloud::OSS::OssClient *OssManager::ossClient = nullptr;
