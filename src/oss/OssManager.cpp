#include "oss/OssManager.h"

#include <QDebug>
#include <QString>
#include <QtConcurrent/QtConcurrent>
#include <cstring>

#include "oss/EndPoints.h"
#include "util/ThreadHelper.h"

apr_pool_t *OssManager::pool;
oss_request_options_t *OssManager::options;

void OssManager::loginFromUi(LoginSplashDialog &dialog) {
    auto url = EndPoints::getNameAndUrl().value(dialog.getUi().endpointSelect->currentText());
    if (url == nullptr || url.isEmpty()) {
        return;
    }
    // ReSharper disable once CppNoDiscardExpression
    QtConcurrent::run([&dialog, url]() -> void {
        bool b = loginInternal(dialog, *dialog.getUi().loginButton, url, dialog.getUi().account->text(), dialog.getUi().password->text());
        if (b) {
            ThreadHelper::runInMainThread([&dialog]() -> void {
                dialog.accept();
            });
        }
    });
}

void OssManager::loginFromSaved() {
    // TODO
}

void fill(aos_string_t &target,const QString &from) {
    free(target.data);
    target.data = new char[from.length() + 1];
    // ReSharper disable once CppDeprecatedEntity
    strcpy(target.data, from.toUtf8().toStdString().c_str());
    target.len = from.length() + 1; // NOLINT(*-narrowing-conversions)
}

bool OssManager::loginInternal(LoginSplashDialog &dialog, QPushButton &button, const QString &endpointUrl, const QString &id, const QString &accessKey) {
    ThreadHelper::runInMainThread([&]() -> void {
        button.setEnabled(false);
        button.setText("正在连接到服务器...");
    });
    options->config = oss_config_create(options->pool);
    fill(options->config->endpoint,endpointUrl);
    fill(options->config->access_key_id,id);
    fill(options->config->access_key_secret,accessKey);
    options->config->is_cname = 0;
    options->ctl = aos_http_controller_create(options->pool, 0);
    ThreadHelper::runInMainThread([&]() -> void {
        button.setText("正在验证服务可用性...");
    });
    aos_table_t *resp_headers = nullptr;
    const auto params = oss_create_list_buckets_params(pool);
    const auto resp_status = oss_list_bucket(options, params, &resp_headers);
    if (aos_status_is_ok(resp_status)) {
        return true;
    } else {
        ThreadHelper::runInMainThread([&button, resp_status]() -> void {
            button.setText("登录失败：" + QString::fromUtf8(resp_status->error_msg));
            button.setEnabled(true);
        });
        return false;
    }
}
