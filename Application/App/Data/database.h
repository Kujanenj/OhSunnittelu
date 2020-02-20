#ifndef DATABASE_H
#define DATABASE_H

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

#define TABLE                   "Results"
#define TABLE_YEAR              "year"
#define TABLE_DIST              "distance"
#define TABLE_TIME              "time"
#define TABLE_PLACE             "place"
#define TABLE_PLACEM            "placeM"
#define TABLE_PLACEN            "placeN"
#define TABLE_GENDER            "gender"
#define TABLE_SFNAME            "SFname"
#define TABLE_CITY              "city"
#define TABLE_NATIONALITY       "nationality"
#define TABLE_AGE               "age"
#define TABLE_TEAM              "team"

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();
    void connectToDataBase();

public slots:
    void inserIntoTable(QVector<QString> toInsert);      // Adding entries to the table
    void removeData();

private:
    QSqlDatabase db;

    bool openDataBase();
    void createDataBase();
    void closeDataBase();
    void createTable();

    QVector<QString> data;
    QString errorMessage_="No errors";
};

#endif // DATABASE_H
