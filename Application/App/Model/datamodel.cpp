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

    calc_->getMinMaxResults(listedData_);
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

void DataModel::sortDataBase(QString field)
{
    database_->sortDataBase(field);
}


//tänne voi ja pitää lisätä noita parametrei.. jos haluu esim ettiä kahen jutun perusteella
QVector<QVector<QString> > DataModel::searchDataBase(QMap<QString, QString> config)
{
    QString searchParameter="SELECT "+ config["select"] + " FROM " + config["from"]
            + " WHERE " + config["where"] +" " +  config["command"] + " " + config["toSearch"];
    qDebug()<<searchParameter;
    return database_->searchDataBase(searchParameter);
}
}
