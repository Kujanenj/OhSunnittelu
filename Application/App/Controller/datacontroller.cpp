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
                                  QString distance, QString gender, QString ageSeries,
                                  QString firstName, QString lastName,
                                  QString place, QString nationality,
                                  QString team)
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



    parameters.insert("Matka", distance);
    parameters.insert("Ikaluokka", ageSeries);
    parameters.insert("Kansalaisuus", nationality);
    parameters.insert("Sukupuoli", gender);
    parameters.insert("Etunimi", firstName);
    parameters.insert("Sukunimi", lastName);
    parameters.insert("Paikkakunta", place);
    parameters.insert("Joukkue", team);
    for(int i = 0; i <= size; i++) {
        QString s;
        s = QString::number(startYear.toInt() + i);
        qDebug() << s;
        parameters.insert("Vuosi", s);

        try {
            dataModel_->doRequest(parameters);
            dataModel_->doParse(parserConfig_);
            dataModel_->insertData();
        } catch (QString msg) {
            qDebug()<<msg<< endl << " continuing search";
        }

    }
}

void DataController::sortButtonClicked(QString selectedField)
{

    dataModel_->sortDataBase(selectedField);
    //SELECT * FROM Results WHERE SFName LIKE '%Ville%',
    // eli siis kaikki Villet
    QMap<QString, QString> config = {{"select","*"},
                                     {"from","Results"},
                                     {"where","SFname"},
                                     {"command","LIKE"},
                                     {"toSearch","'%Ville%'"}};
    dataModel_->searchDataBase(config);
}

} // Namespace controller
