#ifndef ENDPOINTS_H
#define ENDPOINTS_H

#include <QString>


class EndPoints {
public:
    static QMap<QString, QString> &getNameAndUrl();

    static void init();

    EndPoints(const EndPoints &) = delete;

    EndPoints &operator=(const EndPoints &) = delete;

private:
    static QMap<QString, QString> nameAndUrl;
};

#endif
