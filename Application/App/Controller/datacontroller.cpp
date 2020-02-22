#include "datacontroller.h"
#include <QDebug>

namespace Controller
{


DataController::DataController(std::shared_ptr<DataBase> database, QObject *parent ) :
    QObject(parent),
    database_(database)
{

    dataModel_=std::make_shared<Model::DataModel>(database);
    qDebug() << "DataController created";
}

DataController::~DataController()
{

    database_->removeData();
    qDebug() << "DataController removed";
}

void DataController::searchButtonClicked(QString startYear, QString endYear,
                                  QString distance, QString gender, QString ageSeries,
                                  QString firstName, QString lastName,
                                  QString place, QString nationality,
                                  QString team)
{
    // Changes nationality text to match with all nationalities
    if(nationality == "All"){
        nationality = "0";
    }

    // Takes 2 nationality symbol letters
    nationality = nationality.left(2);

    QMap<QString,QString> parameters;

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

     dataModel_->doRequest(parameters);
     dataModel_->doParse(parserConfig_);
     dataModel_->insertData();


}

void DataController::sortButtonClicked(QString selectedField)
{

    dataModel_->sortDataBase(selectedField);
}

} // Namespace controller
