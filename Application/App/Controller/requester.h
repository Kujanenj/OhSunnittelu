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
 * @brief The Requester class
 * Used to gather data from website and send it to parser
 */
class Requester : public QObject
{
    Q_OBJECT
public:
    explicit Requester(QObject *parent = 0);

    ~Requester();

    /**
     * @brief DoRequest
     * Tries to start request if there are no errors
     * @return
     */
    QString DoRequest(QMap<QString,QString>);

public slots:

    /**
     * @brief replyFinished
     * Writes reply to file if reply is successful
     * and calls parser to parse file
     * @param reply
     */
    void replyFinished (QNetworkReply *reply);

private:

    /**
     * @brief requestData
     * Uses QNetworkAccessManager to make post request to website
     */
    void requestData();

    QNetworkAccessManager *manager;
    QMap<QString, QString> parameters_;
};

#endif // REQUESTER_H
