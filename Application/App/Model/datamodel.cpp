#include "datamodel.h"

namespace Model {

DataModel::DataModel(std::shared_ptr<DataBase> database)
{
    req = std::make_shared<Model::Requester>();
    parser = std::make_shared<Model::Parser>();
    calc_=std::make_shared<Calculator>();
    database_=database;
    qDebug()<<"Datamodel created";
}

void DataModel::doRequest(QMap<QString,QString> requesterParameters, QMap<QString,QString> parserParameters)
{

    req->DoRequest(requesterParameters,data_);
    doParse(parserParameters);
}

void DataModel::doParse(QMap<QString, QString> config)
{
    parser->fullParse(config,data_);
}

void DataModel::insertData(QString table)
{
    //Note: Please never ever touch anything here if you want to keep your iq levels where they are.
    listedData_=parser->getListedData();
    if(listedData_.size()==0 && table=="Results"){
        qDebug()<<"Nothing to insert";
        return;
    }

    try {


     QSqlDatabase::database().transaction();

    if(table=="Analytics"){
        if(analyticsFULL_.size()==0){
            qDebug()<<"Empty analytics";
            return;
        }
        qDebug()<<"Analytics insertion";
        database_->insertIntoTable(analyticsFULL_,table);
        qDebug()<<"Analytics insertion successs";

    }
    else{

        qDebug()<<"Regular insertion";
        database_->insertIntoTable(listedData_,table);
        qDebug()<<"Regular insertion succesess";
    }

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

    QSqlDatabase::database().commit();
}

void DataModel::sortDataBase(QString sqlcommand)
{
    database_->sortDataBase(sqlcommand);
}

void DataModel::analytics(QVector<QString> distances, std::pair<QString,QString> years)
{
    analyticsFULL_.clear();
    QVector<QVector<QString>> sqlResults; //<Distance<muut<result>>

    QVector<QString> analyticsPARTIAL;
    QVector<std::pair<QString,QString>> teamResults;
    std::pair<QString,QString> teamResultsPartial;
    int startYear=years.first.toInt();
    int endYear=years.second.toInt();
    QString sqlCommand;

    //loop all years
    for(int yearIndex=startYear; yearIndex<=endYear; yearIndex++){
        for(int i=0; i<distances.size(); i++){
            qDebug()<<"New distance in analytics"<<distances.at(i);
            sqlCommand="SELECT * FROM Results WHERE distance LIKE '%"+distances.at(i) +"%' AND year LIKE '%" + QString::number(yearIndex) + "%'";

            sqlResults=searchDataBase(sqlCommand);
            if(sqlResults.size()>=3){
                analyticsPARTIAL=calc_->calculateAnalytics(sqlResults);
                teamNames_.clear();
                teamNames_=parser->getTeamNames();

                //Loop teams
                for(int it=0; it<teamNames_.size(); it++){ //create a vec of all teams and their average times <Team,time>

                    sqlCommand="SELECT * FROM Results WHERE team LIKE '%"+teamNames_.at(it)+"%' AND distance LIKE '%"+distances.at(i)+"%' AND year LIKE '%"
                            + QString::number(yearIndex) + "%'";

                    sqlResults=searchDataBase(sqlCommand);

                    if(sqlResults.size()!=0){

                    teamResultsPartial.first=sqlResults.at(0).at(11);
                    teamResultsPartial.second=calc_->calcAverageTime(sqlResults);

                    teamResults.push_back(teamResultsPartial);

                    }
                }

                analyticsPARTIAL.push_back(calc_->getBestTeam(teamResults).first);
                teamResults.clear();
                analyticsFULL_.push_back(analyticsPARTIAL);
                analyticsPARTIAL.clear();
            }
        }
    }
    qDebug()<<"End of analytics";
    parser->clearTeams();
}

QVector<QVector<QString>> DataModel::getAnalyticsVector()
{
    return analyticsFULL_;
}

QVector<QVector<QString>> DataModel::searchDataBase(QString sqlCommand)
{
    return database_->searchDataBase(sqlCommand);
}

QVector<std::pair<QString, float> > DataModel::getCountries(QString sqlCommand)
{
    return calc_->calculateCountries(database_->searchDataBase(sqlCommand));
}

QVector<std::pair<QString, float> > DataModel::getDistances(QString sqlCommand)
{
    return calc_->calculateDistances(database_->searchDataBase(sqlCommand));
}

float DataModel::timeToFloat(QString time)
{
    return calc_->TimeStringToInt(time);
}

} // Namespace Model
