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
                    dataModel_->doRequest(parameters,parserConfig_);
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
            if(distances.at(0) == "kaikki") {
                distances.clear();
                distances = {"P50", "V50", "P100", "P32", "V20",
                            "V32", "V20jun", "P42", "V32", "P20",
                            "P30", "P44", "P60", "P62", "P25", "P32",
                            "P35", "P45", "P52", "P53", "P75", "V30",
                            "V45", "V53", "V75"};
                qDebug() << "Only one distance";
            }
            dataModel_->analytics(distances,years);
            dataModel_->insertData("Analytics");
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


QVector<int> DataController::getGraphValues(QString graphtype, QString year, QString distance){
    QVector<int> values;
    if(graphtype == "ajat"){
        QString query = "SELECT * FROM Results WHERE distance = '" + distance + "' AND year = '" + year + "' AND place < 11";
        QVector<QVector<QString>> results = dataModel_->searchDataBase(query);

        for(int i = 0; i < results.size(); i++){
            float to_insert = (dataModel_->timeToFloat(results.at(i).at(2)))/3600;
            values.append(static_cast<int>(to_insert*100));
        }
        return values;
    }
    else if(graphtype == "kansallisuudet"){
        QString query = "SELECT * FROM Results WHERE distance = '" + distance + "' AND year = '" + year + "'";
        QVector<std::pair<QString, float> > results = dataModel_->getCountries(query);
        for(int i = 0; i < results.size(); i++){
            values.append(static_cast<int>(results.at(i).second));
        }
        return values;
    }

    else if(graphtype == "parhaat_m"){
        QString query = "SELECT * FROM Results WHERE distance = '" + distance + "' AND place = 1 ORDER BY year";
        QVector<QVector<QString>> results = dataModel_->searchDataBase(query);
        for(int i = 0; i < results.size(); i++){
            float to_insert = (dataModel_->timeToFloat(results.at(i).at(2)))/3600;
            values.append(static_cast<int>(to_insert*100));
        }
        return values;
    }
    else if(graphtype == "osallistujat"){
        QString query = "SELECT * FROM Results WHERE year = '" + year + "'";
        QVector<std::pair<QString, float> > results = dataModel_->getCountries(query);
        for(int i = 0; i < results.size(); i++){
            values.append(static_cast<int>(results.at(i).second));
        }
        return values;
    }
    return {};
}
QVector<QString> DataController::getGraphTypes(QString graphtype, QString year, QString distance){
    if(graphtype == "kansallisuudet"){
        QString query = "SELECT * FROM Results WHERE distance = '" + distance + "' AND year = '" + year + "'";

        QVector<std::pair<QString, float> > results = dataModel_->getCountries(query);

        QVector<QString> kansallisuudet;
        for(int i = 0; i < results.size(); i++){
            kansallisuudet.append(results.at(i).first);
        }
        return kansallisuudet;
    }
    else if(graphtype == "osallistujat"){
        QString query = "SELECT * FROM Results WHERE year = '" + year + "'";

        QVector<std::pair<QString, float> > results = dataModel_->getDistances(query);

        QVector<QString> osallistujat;
        for(int i = 0; i < results.size(); i++){
            osallistujat.append(results.at(i).first);
        }
        return osallistujat;
    }
    return{};
}

} // Namespace controller
