#ifndef REQUESTER_H
#define REQUESTER_H

#include <iostream>
#include "parser.h"
#include <QMap>
#include <QJsonDocument>
#include <QStringList>
#include <QProcess>

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>
#include <QHttpMultiPart>
/**
 * @brief The Requester class Kommentoikaa nyt perkele. Kaikkiin metodeihin kommentoinnit. Ja laittakaa sinne koodin sekaanki vähä niin tajuaas jotai5
 */

class Requester : public QObject
{
    Q_OBJECT
public:
    explicit Requester(QObject *parent = 0);

    ~Requester();

    QString DoRequest(QMap<QString,QString>);

public slots:
    void replyFinished (QNetworkReply *reply);

private:

    /**
     * @brief createJSON
     * Generates JSON file from C++ map
     */
    void createJSON();


    void requestData();

    QNetworkAccessManager *manager;
    QMap<QString, QString> parameters_;
    QVariantMap vmap_;
};

#endif // REQUESTER_H
