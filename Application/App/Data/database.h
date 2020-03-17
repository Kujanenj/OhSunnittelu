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
#include <memory>

#include "abstarctdatabase.h"


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

#define TABLE_2                 "Analytics"
#define TABLE_2_YEAR            "year"
#define TABLE_2_DIST            "distance"
#define TABLE_2_AVGTIME         "avgtime"
#define TABLE_2_PARTICIPANTS    "participants"
#define TABLE_2_FASTESTTIME     "fastesttime"
#define TABLE_2_SLOWESTTIME     "slowesttime"
#define TABLE_2_WINNER          "winner"
#define TABLE_2_SECOND          "second"
#define TABLE_2_THIRD           "third"
#define TABLE_2_BEST_TEAM       "bestteam"

class DataBase : public AbstarctDatabase
{
    Q_OBJECT
public:
    explicit DataBase(std::shared_ptr<ResultModel> resultModel = nullptr,
                      std::shared_ptr<AnalyticsModel> analyticsModel=nullptr);
    ~DataBase();
    //void connectToDataBase();
    /**
     * @brief sortDataBase sorts the database acording to the sql command
     * @param command
     */
    void sortDataBase(QString command);
    QVector<QVector<QString>> searchDataBase(QString config);
public slots:

    void inserIntoTable(QVector<QString> toInsert);      // Adding entries to the table
    void insertIntoAnalyticsTable(QVector<QString> toInsert);
    void removeData();

private:


    void createTable() override;

    QVector<QString> data;
    QVector<QString> analyticsData;

    QString errorMessage_="No errors";



};

#endif // DATABASE_H
