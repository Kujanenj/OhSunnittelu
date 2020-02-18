#include "database.h"

DataBase::DataBase(QObject *parent)
{

}

DataBase::~DataBase()
{

}

void DataBase::connectToDataBase()
{
    if(!QFile("../../Application/App/Data/" DATABASE_NAME).exists()){
        this->createDataBase();
    } else {
        qDebug() << "Restored old database";
        this->openDataBase();
        inserIntoTable();
    }
}

bool DataBase::createDataBase()
{
    if(this->openDataBase()){
        qDebug() << "Created new database";
        return (this->createTable()) ? true : false;
    } else {
        qDebug() << "Failed to restore the database";
        return false;
    }
}

bool DataBase::openDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName("../../Application/App/Data/" DATABASE_NAME);
    if(db.open()){
        return true;
    }
    return false;
}

void DataBase::closeDataBase()
{
    db.close();
}

bool DataBase::createTable()
{
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " TABLE " ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            TABLE_YEAR     " VARCHAR(255)    NOT NULL,"
                            TABLE_DIST     " VARCHAR(255)    NOT NULL,"
                            TABLE_TIME       " VARCHAR(255)    NOT NULL,"
                            TABLE_PLACE     " VARCHAR(255)    NOT NULL,"
                            TABLE_PLACEM     " VARCHAR(255)    NOT NULL,"
                            TABLE_PLACEN       " VARCHAR(255)    NOT NULL,"
                            TABLE_GENDER     " VARCHAR(255)    NOT NULL,"
                            TABLE_SFNAME     " VARCHAR(255)    NOT NULL,"
                            TABLE_CITY       " VARCHAR(255)    NOT NULL,"
                            TABLE_NATIONALITY     " VARCHAR(255)    NOT NULL,"
                            TABLE_AGE     " VARCHAR(255)    NOT NULL,"
                            TABLE_TEAM     " VARCHAR(255)    NOT NULL"
                        " )"
                    )){
        qDebug() << "DataBase: error of create " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    }
    inserIntoTable();
    return true;
}

bool DataBase::inserIntoTable()
{
    data.push_back("2019");
    data.push_back("P50");
    data.push_back("3:25:56");
    data.push_back("5");
    data.push_back("7");
    data.push_back("");
    data.push_back("M");
    data.push_back("Kujanen Jussi");
    data.push_back("Alahärmä");
    data.push_back("FI");
    data.push_back("35");
    data.push_back("TR3G");

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
        return false;
    }
    return true;
}

bool DataBase::removeData()
{
    QSqlQuery query;
    query.prepare("DELETE FROM " TABLE);

    if(!query.exec()){
        qDebug() << "error delete row " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    }
    qDebug() << "All rows deleted succesfully";
    return true;
}
