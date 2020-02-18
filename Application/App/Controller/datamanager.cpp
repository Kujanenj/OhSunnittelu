#include "datamanager.h"
#include <QDebug>

namespace Controller
{


Datamanager::Datamanager(QObject *parent) : QObject(parent)
{
    req = std::make_shared<Model::Requester>();
    parser = std::make_shared<Model::Parser>();
    qDebug() << "Datamanager luotu";

    QString empty="";


}

Datamanager::~Datamanager()
{
    qDebug()<<"Datamanager poistettu";
}

void Datamanager::searchButtonClicked(QString startYear, QString endYear,
                                  QString distance, QString gender, QString ageSeries,
                                  QString firstName, QString lastName,
                                  QString place, QString nationality,
                                  QString team)
{
    //Condition checks that take out invalid inputs
    if(gender == ""){
        gender = "kaikki";
    }

    if(nationality == "Kaikki"){
        nationality = "0";
    }
    nationality = nationality.left(2);

    QMap<QString,QString> parameters;

    qDebug() << " Vuosi: " << startYear << "\n"
             << "Matka: " << distance << "\n"
             << "Sukupuoli: " << gender << "\n"
             << "Ikäsarja: " << ageSeries << "\n"
             << "Etunimi: " << firstName << "\n"
             << "Sukunimi: " << lastName << "\n"
             << "Paikkakunta: " << place << "\n"
             << "Kansallisuus: " << nationality << "\n"
             << "Joukkue: " << team << "\n";

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

     req->DoRequest(parameters,data_);
     qDebug() << "Request done";

     parser->fullParse(parserConfig_,data_);
     qDebug()<<parser->getListedData();
     qDebug()<<"There should be a lsit above me";
}

}
