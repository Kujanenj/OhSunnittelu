#include "datamodel.h"
namespace Model {


DataModel::DataModel(std::shared_ptr<DataBase> database)
{
    req = std::make_shared<Model::Requester>();
    parser = std::make_shared<Model::Parser>();
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
    parser->clearListedData();

    QSqlDatabase::database().transaction();
    qDebug()<<"Starting the insertion";
    try {
        for(int i=0; i<listedData_.size(); i++){
            qDebug()<<"inserting "<<listedData_.at(i);
            database_->inserIntoTable(listedData_.at(i));
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

void DataModel::sortDataBase(QString field)
{
    database_->sortDataBase(field);
}
}