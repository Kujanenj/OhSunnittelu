#include "downloader.h"



Downloader::Downloader(QObject *parent) :
    QObject(parent)
{

}

void Downloader::doDownload()
{
    // Call the webservice
    manager = new QNetworkAccessManager(this);
    manager->setStrictTransportSecurityEnabled(true);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

    QUrl url("https://www.finlandiahiihto.fi/Tulokset/Tulosarkisto");
    QNetworkRequest request(url);

    //QNetworkRequest::setHeader();
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    request.setRawHeader(QByteArray("origin"), QByteArray("https://www.finlandiahiihto.fi"));

    QUrlQuery params;
    params.addQueryItem("param1", "string");
    params.addQueryItem("param2", "string");

    manager->post(request, params.toString(QUrl::FullyEncoded).toUtf8());
}

void Downloader::replyFinished (QNetworkReply *reply)
{
    if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else
    {
        qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString()<<"response";
        qDebug() << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();
        qDebug() << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
        qDebug() << reply->header(QNetworkRequest::ServerHeader).toString();
        qDebug() << reply->rawHeader(QByteArray("origin"));

        QByteArray bytes = reply->readAll();  // bytes

        //qDebug()<<reply->readAll();

    }
}
