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

void DataModel::doRequest(QMap<QString, QString> parameters)
{
    req->DoRequest(parameters,data_);
}

void DataModel::doParse(QMap<QString, QString> config)
{
    parser->fullParse(config,data_);
}

void DataModel::insertData()
{
    listedData_=parser->getListedData();
    if(listedData_.size()==0){
        qDebug()<<"Nothing to insert";
        return;
    }


    parser->clearListedData();
    teamNames_.clear();


    QSqlDatabase::database().transaction();
    qDebug()<<"Starting the insertion";


    try {
        QVector<QString> teamNameVecHolder;


        for(int i=0; i<listedData_.size(); i++){
            database_->insertIntoResultsTable(listedData_.at(i));



                if(listedData_.at(i).at(11)!="-"){
               teamNameVecHolder.push_back(listedData_.at(i).at(11));
        }
        }


                int occ=0;
                QString teamNameHOLDER="";
                for(int i = 0 ; i< teamNameVecHolder.size(); i++){
                    occ=0;
                        teamNameHOLDER= teamNameVecHolder.at(i);
                        for(int it=i; it< teamNameVecHolder.size(); it++){
                            if( teamNameVecHolder.at(it)==teamNameHOLDER){
                                teamNameVecHolder.remove(it);
                                occ++;
                                if(occ==3){
                                    teamNames_.push_back(teamNameHOLDER);
                                    break;
                                }
                            }
                        }
                }
        qDebug()<<"Inserted some data to database";
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

void DataModel::insertAnalyticsData()
{

    QSqlDatabase::database().transaction();

    try {
        for(int i = 0; i < analyticsFULL_.size(); i++) {
            qDebug() << analyticsFULL_.at(i);
            database_->insertIntoAnalyticsTable(analyticsFULL_.at(i));
            QSqlDatabase::database().commit();
            qDebug() << "Inserted data to analytics tab";
        }
    } catch (QString msg) {
        qDebug() << msg;
    }

    QSqlDatabase::database().commit();
}

void DataModel::sortDataBase(QString command)
{
    qDebug()<<"Sorting database";
    database_->sortDataBase(command);
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
            sqlCommand="SELECT * FROM Results WHERE distance LIKE '%"+distances.at(i) +"%' AND year LIKE '%" + QString::number(yearIndex) + "%'";

            sqlResults=searchDataBase(sqlCommand);
            if(sqlResults.size()>=3){
                analyticsPARTIAL=calc_->calculateAnalytics(sqlResults);
                //Loop teams
                for(int it=0; it<teamNames_.size(); it++){ //create a vec of all teams and their average times <Team,time>
                    sqlCommand="SELECT * FROM Results WHERE team like '%"+teamNames_.at(it)+"%'";
                    sqlResults=searchDataBase(sqlCommand);
                    teamResultsPartial.first=sqlResults.at(0).at(11);
                    teamResultsPartial.second=calc_->calcAverageTime(sqlResults);
                    teamResults.push_back(teamResultsPartial);
                }

                analyticsPARTIAL.push_back(calc_->getBestTeam(teamResults).first);

                analyticsFULL_.push_back(analyticsPARTIAL);
                analyticsPARTIAL.clear();

                qDebug() << "Analytics size: " << analyticsFULL_.size();
            }
        }
    }
}

QVector<QVector<QString>> DataModel::getAnalyticsVector()
{
    return analyticsFULL_;
}

QVector<QVector<QString>> DataModel::searchDataBase(QString sqlCommand)
{
    return database_->searchDataBase(sqlCommand);
}

QVector<QString> DataModel::getTeamNames()
{
 //tänne pitäs saada semmonen että antaa listan kaikista uniikeista tiiminimistä jota on jollai tietyl matkal (ja vuodella?)
    return teamNames_;
}

} // Namespace Model
