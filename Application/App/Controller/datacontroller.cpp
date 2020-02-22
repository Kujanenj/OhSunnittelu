#include "datacontroller.h"
#include <QDebug>

namespace Controller
{


DataController::DataController(std::shared_ptr<DataBase> database, QObject *parent ) :
    QObject(parent),
    database_(database)
{
    req = std::make_shared<Model::Requester>();
    parser = std::make_shared<Model::Parser>();
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

     req->DoRequest(parameters,data_);
     qDebug() << "Request done";

     // Parses data to dataVector_ and clears old listedData_ vector
     parser->fullParse(parserConfig_,data_);
     dataVector_=parser->getListedData();
     parser->clearListedData();



             database_->removeData();
             QSqlDatabase::database().transaction();
     qDebug()<<"Starting the insertion";
     try {
         for(int i=0; i<dataVector_.size(); i++){
             qDebug()<<"inserting "<<dataVector_.at(i);
             database_->inserIntoTable(dataVector_.at(i));
         }
           QSqlDatabase::database().commit();
     } catch (QString msg) {
         qDebug()<<msg;
         try {
             database_->removeData();
             qDebug()<<"removed all data from database since an error was thrown. Next error will cause me to destroy this program!";
         } catch (QString msg_) {
             qDebug()<<msg_;
             qDebug()<<"I told you this would happen. I will suicide now, goodbye!";
             delete this;
         }
     }




}

void DataController::sortButtonClicked(QString selectedField)
{

 //   QSqlDatabase::database().transaction();
    qDebug()<<selectedField;
    database_->sortDataBase(selectedField);
}

} // Namespace controller
