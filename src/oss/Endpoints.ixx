module;

#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QMap>
#include <QString>
#include <QJsonObject>

export module oss.endpoints;

export class EndPoints {
public:
    static QMap<QString, QString> &getnameAndUrl() {
        return nameAndUrl;
    }

    //TODO warning
    static void init() {
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

    EndPoints(const EndPoints &) = delete;

    EndPoints &operator=(const EndPoints &) = delete;

private:
    static QMap<QString, QString> nameAndUrl;
};

QMap<QString, QString> EndPoints::nameAndUrl;
