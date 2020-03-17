#ifndef ABSTARCTDATABASE_H
#define ABSTARCTDATABASE_H

#include "../Model/analyticsmodel.h"
#include "../Model/resultmodel.h"


#include <memory>
#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>



#define DATABASE_HOSTNAME       "NameDataBase"
#define DATABASE_NAME           "data.db"


class AbstarctDatabase : public QObject
{
public:
    AbstarctDatabase(std::shared_ptr<ResultModel> rModel,
                     std::shared_ptr<AnalyticsModel> aModel);

    void connectToDataBase();

protected:
    void createDataBase();
    bool openDataBase();
    void closeDataBase();
    virtual void createTable()=0;


    QSqlDatabase db;
    std::shared_ptr<AnalyticsModel> aModel_=nullptr;
    std::shared_ptr<ResultModel> rModel_=nullptr;
private:
    QString errorMessage_="No errors!";
};

#endif // ABSTARCTDATABASE_H
