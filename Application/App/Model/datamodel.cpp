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
        qDebug()<<"---------------------------";
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

void DataModel::analytics(QString distance,QString year)
{

    QVector<QString> distances;

    if (distance == "kaikki")
    {
        distances.clear();
        distances = { "P50", "V50", "P100", "P32", "V20", "V32", "V20jun", "P42", "V32",
            "P20", "P30", "P44", "P60", "P62", "P25", "P32", "P35", "P45", "P52", "P53",
            "P75", "V30", "V45", "V53", "V75" };

    }
    else{
        distances.append(distance);
    }

        analyticsFULL_.clear();
        QVector<QVector<QString>> sqlResults; //<Distance<muut<result>>

        QVector<QString> analyticsPARTIAL;
        QVector<std::pair<QString,QString>> teamResults;
        std::pair<QString,QString> teamResultsPartial;

        QString sqlCommand;

        //loop all distances
        for(int i =0; i<distances.size(); i++){




                sqlCommand="SELECT * FROM Results WHERE distance LIKE '%"+distances.at(i) +"%' AND year LIKE '%" + year + "%'";

                sqlResults=searchDataBase(sqlCommand);

                if(sqlResults.size()>=3){
                    analyticsPARTIAL=calc_->calculateAnalytics(sqlResults);
                    teamNames_=parser->getTeamNames(distances.at(i),year);

                    //Loop teams
                if(teamNames_.size()==0){
                    analyticsPARTIAL.push_back("-");

                }

                else{
                    for(int it=0; it<teamNames_.size(); it++){ //create a vec of all teams and their average times <Team,time>
                        sqlCommand="SELECT * FROM Results WHERE team LIKE '%"+teamNames_.at(it)+"%' AND distance LIKE '%"+distances.at(i)+"%' AND year LIKE '%"
                                + year + "%'";

                        sqlResults=searchDataBase(sqlCommand);
                        if(sqlResults.size()!=0){

                        teamResultsPartial.first=sqlResults.at(0).at(11);
                        teamResultsPartial.second=calc_->calcAverageTime(sqlResults);

                        teamResults.push_back(teamResultsPartial);

                        }
                    }

                    analyticsPARTIAL.push_back(calc_->getBestTeams(teamResults,1).at(0).first);
                    teamResults.clear();
                }

                    analyticsFULL_.push_back(analyticsPARTIAL);

                    analyticsPARTIAL.clear();
                }

    }
        qDebug()<<"End of analytics";

    }

QVector<QVector<QString>> DataModel::getAnalyticsVector()
{
    return analyticsFULL_;
}

QVector<QVector<QString>> DataModel::searchDataBase(QString sqlCommand)
{
    return database_->searchDataBase(sqlCommand);
}

QVector<std::pair<QString, float> > DataModel::getPercanteges(QString sqlCommand, int index)
{
    return calc_->calculatePercentagesGeneral(database_->searchDataBase(sqlCommand),index);
}


float DataModel::timeToFloat(QString time)
{
    return calc_->TimeStringToInt(time);
}

QVector<std::pair<QString, QString> > DataModel::getBestTeams(int amount, QString year,QString distance)
{
    QVector<QVector<QString>> sqlResults;
    QString sqlCommand;
    QVector<std::pair<QString,QString>> teamResults;
    teamNames_=parser->getTeamNames(distance,year);
    for(int it=0; it<teamNames_.size(); it++){ //create a vec of all teams and their average times <Team,time>

        sqlCommand="SELECT * FROM Results WHERE team LIKE '%"+teamNames_.at(it)+"%' AND distance LIKE '%"+distance+"%' AND year LIKE '%"
                + year + "%'";

        sqlResults=searchDataBase(sqlCommand);

        if(sqlResults.size()!=0){

        teamResults.push_back({sqlResults.at(0).at(11),calc_->calcAverageTime(sqlResults)});

        }
    }
    return(calc_->getBestTeams(teamResults,amount));
}

void DataModel::clearPars()
{
    parser->clearTeams();
}

} // Namespace Model
