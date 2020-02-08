#include "backend.h"
#include <QDebug>

Backend::Backend(QObject *parent) : QObject(parent)
{
    req = new Requester;
}

Backend::~Backend()
{
    qDebug() << "Requester object deleted";
    delete req;
}

void Backend::searchButtonClicked()
{
    QMap<QString,QString> parameters;
     parameters.insert("dnn$ctr1025$Etusivu$ddlVuosi2x", "2019");
     parameters.insert("dnn$ctr1025$Etusivu$ddlMatka2x", "P50");
     parameters.insert("dnn$ctr1025$Etusivu$ddlIkaluokka2", "kaikki");
     parameters.insert("dnn$ctr1025$Etusivu$ddlKansalaisuus2x", "");
     parameters.insert("dnn$ctr1025$Etusivu$chkLstSukupuoli2", "kaikki");
     parameters.insert("dnn$ctr1025$Etusivu$txtHakuEtunimi2", "Veikko");
     parameters.insert("dnn$ctr1025$Etusivu$txtHakuSukunimi2", "");
     parameters.insert("dnn$ctr1025$Etusivu$txtHakuPaikkakunta2", "");
     parameters.insert("dnn$ctr1025$Etusivu$txtHakuJoukkue2", "");
     req->DoRequest(parameters);

     qDebug() << "Request done";

    //Call the requester maybe??
    qDebug()<<"UI Search button clicked";
}

const QString Backend::text(){
    return mText;
}

void Backend::setText(const QString &text){
    qDebug() << text << "Field: " << fieldText;
    if(text == mText)
        return;
    mText = text;
    emit textChanged(mText);
    qDebug()<<"Text input field value has been modified via UI";
}
