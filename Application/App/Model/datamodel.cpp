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

    QSqlDatabase::database().transaction();
    qDebug()<<"Starting the insertion";


    try {
        for(int i=0; i<listedData_.size(); i++){
            database_->inserIntoTable(listedData_.at(i));
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

void DataModel::sortDataBase(QString command)
{
    qDebug()<<"Sorting database";
    database_->sortDataBase(command);
}

void DataModel::analytics(QVector<QString> distances)
{
    QVector<QVector<QString>> sqlResults; //<Distance<muut<result>>
    QVector<QVector<QString>> analyticsFULL;
    QVector<QString> analyticsPARTIAL;
    QString sqlCommand;

    for(int i=0; i<distances.size(); i++){
        sqlCommand="SELECT * FROM Results WHERE distance LIKE '%"+distances.at(i) +"%'";

        sqlResults=searchDataBase(sqlCommand);
        if(!sqlResults.empty()){

        analyticsPARTIAL.push_back(calc_->calcAverageTime(sqlResults));
        analyticsPARTIAL.push_back(QString::number(sqlResults.size()));
        analyticsPARTIAL.push_back(sqlResults.first().at(2));
        analyticsPARTIAL.push_back(sqlResults.last().at(2));

        analyticsPARTIAL.push_back(sqlResults.first().at(7));
        if(!(sqlResults.size() <= 3 )){
        analyticsPARTIAL.push_back(sqlResults.at(1).at(7));
        analyticsPARTIAL.push_back(sqlResults.at(2).at(7));
        }

        analyticsFULL.push_back(analyticsPARTIAL);
        analyticsPARTIAL.clear();

        //Tähän viel sit jotenki bestTeam
    }

    }
}




QVector<QVector<QString> > DataModel::searchDataBase(QString sqlCommand)
{

    return database_->searchDataBase(sqlCommand);
}

QVector<QString> DataModel::getTeamNames(QString distance)
{
 //tänne pitäs saada semmonen että antaa listan kaikista uniikeista tiiminimistä jota on jollai tietyl matkal (ja vuodella?)

}
}
