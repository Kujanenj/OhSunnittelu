#include "datacontroller.h"
#include <QDebug>

namespace Controller
{


DataController::DataController(std::shared_ptr<Model::DataModel> model, QObject *parent ) :
    QObject(parent)
{

    dataModel_=model;
    qDebug() << "DataController created";
}

DataController::~DataController()
{

    database_->removeData();
    qDebug() << "DataController removed";
}

void DataController::searchButtonClicked(QString startYear, QString endYear,
                                  QVector<QString> distances, QString gender, QVector<QString> ages,
                                  QString firstName, QString lastName,
                                  QString place, QString nationality,
                                  QString team, QString personalSearch)
{ 
    database_->removeData();

    // Changes nationality text to match with all nationalities
    if(nationality == "All"){
        nationality = "0";
    }

    // Takes 2 nationality symbol letters
    nationality = nationality.left(2);

    QMap<QString,QString> parameters;

    int size = endYear.toInt() - startYear.toInt();

    parameters.insert("Kansalaisuus", nationality);
    parameters.insert("Sukupuoli", gender);
    parameters.insert("Etunimi", firstName);
    parameters.insert("Sukunimi", lastName);
    parameters.insert("Paikkakunta", place);
    parameters.insert("Joukkue", team);

    //MULTISEARCH FOR YEAR, DISTANCE, AGESERIES
    for(int i = 0; i <= size; i++) {

        //YEAR
        QString s;
        s = QString::number(startYear.toInt() + i);
        qDebug() << s;        
        parameters.insert("Vuosi", s);

        //DISTANCES LOOPING
        for(int j = 0; j < distances.size(); j++){
            QString distance = distances.at(j);
            qDebug() << distance;
            parameters.insert("Matka", distance);

            //AGES LOOPING
            for(int k = 0; k < ages.size(); k++){
                QString age = ages.at(k);
                qDebug() << age;
                parameters.insert("Ikaluokka", age);

                try{
                    dataModel_->doRequest(parameters);
                    dataModel_->doParse(parserConfig_);
                    dataModel_->insertData(personalSearch);

                }
                catch (QString msg){
                    qDebug()<<msg<< endl << " continuing search";
                }
            }
        }
    }
    try {
        qDebug() << firstName;
        if(firstName == "" && lastName == "" && team == "" && place == "" && nationality == "0") {
            std::pair<QString, QString> years={startYear,endYear};
            dataModel_->analytics(distances,years);
            dataModel_->insertAnalyticsData();
        }
    } catch (...) {
        qDebug()<<"Viduigsi meni! Ebin:D";
        delete this;
    }
}

void DataController::sortButtonClicked(QString selectedField, QString lowerBound, QString upperBound, QString rankSilder)
{

    QString command = "SELECT * FROM Results WHERE PLACE <= " + rankSilder +  " AND TIME < " + upperBound
            + " AND TIME > "+ lowerBound + " ORDER BY " + selectedField+ " ASC";
    qDebug()<<command;
    dataModel_->sortDataBase(command);

}

int DataController::someData()
{
    return  5;
}

} // Namespace controller
