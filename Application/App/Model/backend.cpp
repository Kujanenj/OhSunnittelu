#include "backend.h"
#include <QDebug>

Backend::Backend(QObject *parent) : QObject(parent)
{
    req = new Requester;
}

Backend::~Backend()
{
    qDebug()<<"back end poistettu";
}

void Backend::searchButtonClicked()
{
    QMap<QString,QString> parameters;
     parameters.insert("Vuosi", "2015");
     parameters.insert("Matka", "P50");
     parameters.insert("Ikaluokka", "kaikki");
     parameters.insert("Kansalaisuus", "0");
     parameters.insert("Sukupuoli", "kaikki");
     parameters.insert("Etunimi", "Ville");
     parameters.insert("Sukunimi", "");
     parameters.insert("Paikkakunta", "");
     parameters.insert("Joukkue", "");
    qDebug()<< req->DoRequest(parameters);

     qDebug() << "Request done";

    //Call the requester maybe??
    qDebug()<<"UI Search button clicked";


}

QString Backend::text(){
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
