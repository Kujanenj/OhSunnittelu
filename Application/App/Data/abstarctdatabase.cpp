#include "abstarctdatabase.h"

AbstarctDatabase::AbstarctDatabase(std::shared_ptr<ResultModel> rModel,
                                   std::shared_ptr<AnalyticsModel> aModel,
                                   std::shared_ptr<PersonalResultModel> pModel)
{
    rModel_=rModel;
    aModel_=aModel;
    pModel_ = pModel;
}

void AbstarctDatabase::connectToDataBase()
{
    if(!QFile("../../Application/App/Data/" DATABASE_NAME).exists()){
        this->createDataBase();
    }
    else {
        qDebug() << "Restored old database";
        this->openDataBase();
    }
}

void AbstarctDatabase::createDataBase()
{
    if(this->openDataBase()){
        qDebug() << "Created new database";
        this->createTable();
    }
    else {
        errorMessage_="Failed to restore the database";
        throw errorMessage_;
    }
}

bool AbstarctDatabase::openDataBase()
{
    qDebug() << "Opening database";

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName("../../Application/App/Data/" DATABASE_NAME);
    if(!db.open()){
        qDebug()<<"Error in opening database";
        return false;
    }
    return true;
}

void AbstarctDatabase::closeDataBase()
{
    db.close();
}
