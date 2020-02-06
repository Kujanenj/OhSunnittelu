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

    /**
     * @brief createMap
     * Inserts parameters to the map
     */
    void createMap();

    /**
     * @brief createJSON
     * Generates JSON file from C++ map
     */
    void createJSON();

    /**
     * @brief startPScript
     * Starts python script to request data
     */
    void startPScript();

    /**
     * @brief parseData
     *
     */
    void parseData();

private:
    QMap<QString, QString> parameters;
    QVariantMap vmap;
};

#endif // REQUESTER_H
