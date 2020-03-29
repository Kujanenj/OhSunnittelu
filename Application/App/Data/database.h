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

#define TABLE_3                  "PersonalResults"
#define TABLE_3_YEAR              "year"
#define TABLE_3_DIST              "distance"
#define TABLE_3_TIME              "time"
#define TABLE_3_PLACE             "place"
#define TABLE_3_PLACEM            "placeM"
#define TABLE_3_PLACEN            "placeN"
#define TABLE_3_GENDER            "gender"
#define TABLE_3_SFNAME            "SFname"
#define TABLE_3_CITY              "city"
#define TABLE_3_NATIONALITY       "nationality"
#define TABLE_3_AGE               "age"
#define TABLE_3_TEAM              "team"

/**
 * @brief The DataBase class
 * is used to create different tables and insert data on them.
 * Also removing and searching from database happens here.
 */
class DataBase : public AbstarctDatabase
{
    Q_OBJECT
public:

    /**
     * @brief DataBase
     * Constructor for database
     * @param resultModel : pointer to resultmodel
     * @param analyticsModel : pointer to analyticsmodel
     */
    explicit DataBase(std::shared_ptr<ResultModel> resultModel = nullptr,
                      std::shared_ptr<AnalyticsModel> analyticsModel = nullptr,
                      std::shared_ptr<PersonalResultModel> personalResultModel = nullptr);

    ~DataBase();

    /**
     * @brief sortDataBase sorts the database acording to the sql command
     * @param command : year, distance, etc.. to tell how to sort
     */
    void sortDataBase(QString command);

    /**
     * @brief searchDataBase
     * @param config
     * @return sumVector: which contains all results matching
     * with sql query
     */
    QVector<QVector<QString>> searchDataBase(QString config);

public slots:

    /**
     * @brief insertIntoResultsTable
     * Inserts results data to SQL table
     * @param toInsert : Data
     */
    void insertIntoResultsTable(QVector<QString> toInsert);

    /**
     * @brief insertIntoAnalyticsTable
     * Inserts analytics data to SQL table
     * @param toInsert : Data
     */
    void insertIntoAnalyticsTable(QVector<QString> toInsert);

    void insertIntoPersonalResultTable(QVector<QString> toInsert);

    /**
     * @brief removeData
     * Removes all results and analytics data
     */
    void removeData();

private:

    /**
     * @brief createTable
     * Creates tables for results and analytics
     */
    void createTable() override;

    QVector<QString> data;
    QVector<QString> analyticsData;
    QVector<QString> personalData;
    QString errorMessage_="No errors";
};

#endif // DATABASE_H
