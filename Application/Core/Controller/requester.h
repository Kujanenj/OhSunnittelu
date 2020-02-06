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


    QString DoRequest(QMap<QString,QString>);



private:


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






    QMap<QString, QString> parameters_;
    QVariantMap vmap_;
};

#endif // REQUESTER_H
