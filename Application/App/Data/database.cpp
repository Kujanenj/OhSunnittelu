#include "database.h"

DataBase::DataBase(std::shared_ptr<ResultModel> resultModel,
                   std::shared_ptr<AnalyticsModel> analyticsModel,
                   std::shared_ptr<PersonalResultModel> personalResultModel)
    :AbstarctDatabase(resultModel,analyticsModel,personalResultModel)
{
}

DataBase::~DataBase()
{
    qDebug() << "Database destroyed!";
}

void DataBase::createTable()
{
    QSqlQuery query;

    if(!query.exec( "CREATE TABLE " TABLE " ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            TABLE_YEAR              " VARCHAR(255)    NOT NULL,"
                            TABLE_DIST              " VARCHAR(255)    NOT NULL,"
                            TABLE_TIME              " VARCHAR(255)    NOT NULL,"
                            TABLE_PLACE             " INT,"
                            TABLE_PLACEM            " INT,"
                            TABLE_PLACEN            " INT,"
                            TABLE_GENDER            " VARCHAR(255)    NOT NULL,"
                            TABLE_SFNAME            " VARCHAR(255)    NOT NULL,"
                            TABLE_CITY              " VARCHAR(255)    NOT NULL,"
                            TABLE_NATIONALITY       " VARCHAR(255)    NOT NULL,"
                            TABLE_AGE               " VARCHAR(255)    NOT NULL,"
                            TABLE_TEAM              " VARCHAR(255)    NOT NULL"
                        " )"
                    ) ||
            !query.exec("CREATE TABLE " TABLE_2 " ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                        TABLE_2_YEAR              " INT,"
                        TABLE_2_DIST              " VARCHAR(255)    NOT NULL,"
                        TABLE_2_AVGTIME           " VARCHAR(255)    NOT NULL,"
                        TABLE_2_PARTICIPANTS      " INT,"
                        TABLE_2_FASTESTTIME       " VARCHAR(255)    NOT NULL,"
                        TABLE_2_SLOWESTTIME       " VARCHAR(255)    NOT NULL,"
                        TABLE_2_WINNER            " VARCHAR(255)    NOT NULL,"
                        TABLE_2_SECOND            " VARCHAR(255)    NOT NULL,"
                        TABLE_2_THIRD             " VARCHAR(255)    NOT NULL,"
                        TABLE_2_AVERAGESPEED      " VARCHAR(255)    NOT NULL,"
                        TABLE_2_WINNERSPEED       " VARCHAR(255)    NOT NULL,"
                        TABLE_2_BEST_TEAM         " VARCHAR(255)    NOT NULL"
                        " )"
                        ) ||
            !query.exec( "CREATE TABLE " TABLE_3 " ("
                                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                    TABLE_3_YEAR              " VARCHAR(255)    NOT NULL,"
                                    TABLE_3_DIST              " VARCHAR(255)    NOT NULL,"
                                    TABLE_3_TIME              " VARCHAR(255)    NOT NULL,"
                                    TABLE_3_PLACE             " INT,"
                                    TABLE_3_PLACEM            " INT,"
                                    TABLE_3_PLACEN            " INT,"
                                    TABLE_3_GENDER            " VARCHAR(255)    NOT NULL,"
                                    TABLE_3_SFNAME            " VARCHAR(255)    NOT NULL,"
                                    TABLE_3_CITY              " VARCHAR(255)    NOT NULL,"
                                    TABLE_3_NATIONALITY       " VARCHAR(255)    NOT NULL,"
                                    TABLE_3_AGE               " VARCHAR(255)    NOT NULL,"
                                    TABLE_3_TEAM              " VARCHAR(255)    NOT NULL"
                                " )"
                            ))
    {
        qDebug() << "DataBase: error of create " << TABLE;
        qDebug() << query.lastError().text();
        errorMessage_= "DataBase: error in creation of table";
        throw errorMessage_;
    }
}

void DataBase::insertIntoResultsTable(QVector<QString> toInsert)
{
    data.clear();
    data=toInsert;

    QSqlQuery query;

    query.prepare("INSERT INTO " TABLE " ( " TABLE_YEAR ", "
                                             TABLE_DIST ", "
                                             TABLE_TIME ", "
                                             TABLE_PLACE ", "
                                             TABLE_PLACEM ", "
                                             TABLE_PLACEN ", "
                                             TABLE_GENDER ", "
                                             TABLE_SFNAME ", "
                                             TABLE_CITY ", "
                                             TABLE_NATIONALITY ", "
                                             TABLE_AGE ", "
                                             TABLE_TEAM " ) "
                  "VALUES (:Year, :Distance, :Time, :Place, :PlaceM, :PlaceN, :Gender, :SFName, :City, :Nationality, :Age, :Team)");
    query.bindValue(":Year",       data[0]);
    query.bindValue(":Distance",       data[1]);
    query.bindValue(":Time",         data[2]);
    query.bindValue(":Place",       data[3]);
    query.bindValue(":PlaceM",       data[4]);
    query.bindValue(":PlaceN",         data[5]);
    query.bindValue(":Gender",       data[6]);
    query.bindValue(":SFName",       data[7]);
    query.bindValue(":City",         data[8]);
    query.bindValue(":Nationality",       data[9]);
    query.bindValue(":Age",       data[10]);
    query.bindValue(":Team",         data[11]);

    if(!query.exec()){
        qDebug() << "error insert into " << TABLE;
        qDebug() << query.lastError().text();
        errorMessage_="Error in insertion to table";
        throw errorMessage_;
    }
}

void DataBase::insertIntoAnalyticsTable(QVector<QString> toInsert)
{
    analyticsData.clear();
    analyticsData=toInsert;

    QSqlQuery query;

    query.prepare("INSERT INTO " TABLE_2 " ( " TABLE_2_YEAR ", "
                                             TABLE_2_DIST ", "
                                             TABLE_2_AVGTIME ", "
                                             TABLE_2_PARTICIPANTS ", "
                                             TABLE_2_FASTESTTIME ", "
                                             TABLE_2_SLOWESTTIME ", "
                                             TABLE_2_WINNER ", "
                                             TABLE_2_SECOND ", "
                                             TABLE_2_THIRD ", "
                                             TABLE_2_AVERAGESPEED ", "
                                             TABLE_2_WINNERSPEED ", "
                                             TABLE_2_BEST_TEAM " ) "
                  "VALUES (:year, :distance, :avgtime, :participants, :fastesttime, :slowesttime, :winner, :second, :third, :averagespeed, :winnerspeed, :bestteam)");
    query.bindValue(":year",            analyticsData[0]);
    query.bindValue(":distance",        analyticsData[1]);
    query.bindValue(":avgtime",         analyticsData[2]);
    query.bindValue(":participants",    analyticsData[3]);
    query.bindValue(":fastesttime",     analyticsData[4]);
    query.bindValue(":slowesttime",     analyticsData[5]);
    query.bindValue(":winner",          analyticsData[6]);
    query.bindValue(":second",          analyticsData[7]);
    query.bindValue(":third",           analyticsData[8]);
    query.bindValue(":averagespeed",    analyticsData[9]);
    query.bindValue(":winnerspeed",     analyticsData[10]);
    query.bindValue(":bestteam",        analyticsData[11]);

    if(!query.exec()){
        qDebug() << "error insert into " << TABLE_2;
        qDebug() << query.lastError().text();
        errorMessage_="Error in insertion to table";
        throw errorMessage_;
    }
}

void DataBase::insertIntoPersonalResultTable(QVector<QString> toInsert)
{
    personalData.clear();
    personalData=toInsert;

    QSqlQuery query;

    query.prepare("INSERT INTO " TABLE_3 " ( " TABLE_3_YEAR ", "
                                             TABLE_3_DIST ", "
                                             TABLE_3_TIME ", "
                                             TABLE_3_PLACE ", "
                                             TABLE_3_PLACEM ", "
                                             TABLE_3_PLACEN ", "
                                             TABLE_3_GENDER ", "
                                             TABLE_3_SFNAME ", "
                                             TABLE_3_CITY ", "
                                             TABLE_3_NATIONALITY ", "
                                             TABLE_3_AGE ", "
                                             TABLE_3_TEAM " ) "
                  "VALUES (:Year, :Distance, :Time, :Place, :PlaceM, :PlaceN, :Gender, :SFName, :City, :Nationality, :Age, :Team)");
    query.bindValue(":Year",       personalData[0]);
    query.bindValue(":Distance",       personalData[1]);
    query.bindValue(":Time",         personalData[2]);
    query.bindValue(":Place",       personalData[3]);
    query.bindValue(":PlaceM",       personalData[4]);
    query.bindValue(":PlaceN",         personalData[5]);
    query.bindValue(":Gender",       personalData[6]);
    query.bindValue(":SFName",       personalData[7]);
    query.bindValue(":City",         personalData[8]);
    query.bindValue(":Nationality",       personalData[9]);
    query.bindValue(":Age",       personalData[10]);
    query.bindValue(":Team",         personalData[11]);

    if(!query.exec()){
        qDebug() << "error insert into " << TABLE;
        qDebug() << query.lastError().text();
        errorMessage_="Error in insertion to table";
        throw errorMessage_;
    }
}

void DataBase::removeData()
{
    QSqlQuery query;
    query.prepare("DELETE FROM " TABLE);

    if(!query.exec()){
        qDebug() << "error delete row " << TABLE;
        qDebug() << query.lastError().text();
        errorMessage_="Databse error in deletion";
        throw errorMessage_;
    }
    query.prepare("DELETE FROM " TABLE_2);

    if(!query.exec()){
        qDebug() << "error delete row " << TABLE_2;
        qDebug() << query.lastError().text();
        errorMessage_="Databse error in deletion";
        throw errorMessage_;
    }
    query.prepare("DELETE FROM " TABLE_3);

    if(!query.exec()){
        qDebug() << "error delete row " << TABLE_3;
        qDebug() << query.lastError().text();
        errorMessage_="Databse error in deletion";
        throw errorMessage_;
    }

    qDebug() << "All rows deleted succesfully";
}

void DataBase::sortDataBase(QString command)
{
    rModel_->sortModel(command);
}

QVector<QVector<QString>> DataBase::searchDataBase(QString config)
{
    QSqlQuery query(config);

    QVector<QVector<QString>> sumVector = {};
    QVector<QString> insertionVector = {};
    QString fieldResult;
    while (query.next()) {
        for(int i = 1; i < 13; i++){
           insertionVector.append(query.value(i).toString());
        }
        sumVector.append(insertionVector);
        insertionVector.clear();
    }

    return sumVector;
}


