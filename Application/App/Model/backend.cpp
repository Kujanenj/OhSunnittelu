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
                                  QString distance, QString gender, QString ageSeries,
                                  QString firstName, QString lastName,
                                  QString place, QString nationality,
                                  QString team)
{

    //Condition checks that take out invalid inputs
    if(gender == ""){
        gender = "kaikki";
    }
    if(ageSeries == "Ikäsarja"){
        ageSeries = "kaikki";
    }
    nationality = nationality.left(2);
    if(nationality != "Kansallisuus"){
        nationality = "0";
    }

    QMap<QString,QString> parameters;

    qDebug()<< startYear + " " + distance + " "
                    + ageSeries + " " + nationality + " "
                    +  gender + " " + firstName + " "
                    + lastName + " " + place + " " + team;

     //Using user input parameters:
     parameters.insert("Vuosi", startYear);
     parameters.insert("Matka", distance);
     parameters.insert("Ikaluokka", ageSeries);
     parameters.insert("Kansalaisuus", nationality);
     parameters.insert("Sukupuoli", gender);
     parameters.insert("Etunimi", firstName);
     parameters.insert("Sukunimi", lastName);
     parameters.insert("Paikkakunta", place);
     parameters.insert("Joukkue", team);

     qDebug()<< req->DoRequest(parameters);
     qDebug() << "Request done";
}
