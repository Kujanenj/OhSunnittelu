#ifndef REQUESTER_H
#define REQUESTER_H

#include <iostream>
#include "parser.h"
#include <QMap>
#include <QJsonDocument>
#include <QStringList>
#include <QProcess>

class Requester
{
public:
    Requester();

    void createMap();

    void createJSON();

    void startPScript();

    void parseData();

private:
    QMap<QString, QString> parameters;
    QVariantMap vmap;
};

#endif // REQUESTER_H
