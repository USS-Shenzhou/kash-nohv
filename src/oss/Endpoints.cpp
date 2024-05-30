#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMap>

#include "oss/EndPoints.h"

QMap<QString, QString> EndPoints::nameAndUrl;

QMap<QString, QString> &EndPoints::getNameAndUrl() {
    return nameAndUrl;
}

//TODO better warning
void EndPoints::init() {
    QFile config("config/Endpoints.json");
    if (!config.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Couldn't open Endpoints.json.";
        return;
    }
    QByteArray configRead = config.readAll();
    config.close();
    QJsonDocument document = QJsonDocument::fromJson(configRead);
    if (!document.isObject()) {
        qWarning() << "Endpoints.json is not a valid JSON object.";
        return;
    }
    QJsonObject jsonObject = document.object();
    for (auto i = jsonObject.begin(); i != jsonObject.end(); ++i) {
        auto key = i.key();
        auto value = i.value().toString();
        nameAndUrl.insert(key, value);
    }
}
