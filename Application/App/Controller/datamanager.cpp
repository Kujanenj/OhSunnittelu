#include "datamanager.h"
#include <QDebug>

namespace Controller
{


Datamanager::Datamanager(std::shared_ptr<DataBase> database, QObject *parent ) :
    QObject(parent),
    database_(database)
{
    req = std::make_shared<Model::Requester>();
    parser = std::make_shared<Model::Parser>();
    QString empty = "";
    qDebug() << "Datamanager luotu";
}

Datamanager::~Datamanager()
{
    database_->removeData();
    qDebug() << "Datamanager poistettu";
}

void Datamanager::searchButtonClicked(QString startYear, QString endYear,
                                  QString distance, QString gender, QString ageSeries,
                                  QString firstName, QString lastName,
                                  QString place, QString nationality,
                                  QString team)
{
    //Condition checks that take out invalid inputs

    qDebug() << nationality;
    if(nationality == "kaikki"){
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

     // Using user input parameters:
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

     // Parses data to dataVector_ and clears old listedData_ vector
     parser->fullParse(parserConfig_,data_);
     dataVector_=parser->getListedData();
     parser->clearListedData();

     // Clears database and starts adding to database
     database_->removeData();
     QSqlDatabase::database().transaction();
     for(int i=0; i < dataVector_.size(); i++){
         database_->inserIntoTable(dataVector_.at(i));
     }
     // Stops adding to database
     QSqlDatabase::database().commit();
}

} // Namespace controller
