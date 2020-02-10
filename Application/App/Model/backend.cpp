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

void Backend::searchButtonClicked(QString startYear, QString endYear,
                                  QString distance, QString gender,
                                  QString firstName, QString lastName,
                                  QString place, QString nationality,
                                  QString team)
{



    //Debugs for QML user inputs
    qDebug()<<"vuosi/vuodet: " + startYear + " <-- >" + endYear;
    qDebug()<<"matka: " + distance;
    qDebug()<<"sukupuoli: " + gender;
    qDebug()<<"etunimi: " + firstName;
    qDebug()<<"sukunimi: " + lastName;
    qDebug()<<"paikkakunta: " + place;
    qDebug()<<"kansallisuus: " + nationality.left(2);
    qDebug()<<"joukkue: " + team;

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
}
