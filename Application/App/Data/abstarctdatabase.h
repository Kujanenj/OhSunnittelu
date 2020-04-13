#ifndef ABSTARCTDATABASE_H
#define ABSTARCTDATABASE_H

#include <memory>
#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

#include "../Model/analyticsmodel.h"
#include "../Model/resultmodel.h"
#include "../Model/personalresultmodel.h"

#define DATABASE_HOSTNAME "NameDataBase"
#define DATABASE_NAME "data.db"

/**
 * @brief The AbstarctDatabase class
 * is used to create SQLite database for skiing results
 */
class AbstarctDatabase : public QObject
{
public:
    /**
     * @brief AbstarctDatabase
     * Constructor that initializes listmodel pointers
     * @param rModel : resultsModel
     * @param aModel : analyticsModel
     */
    AbstarctDatabase(std::shared_ptr<ResultModel> rModel, std::shared_ptr<AnalyticsModel> aModel,
        std::shared_ptr<PersonalResultModel> pModel);

    /**
     * @brief connectToDataBase
     * Makes connection to database
     */
    void connectToDataBase();

protected:
    /**
     * @brief createDataBase
     * Checks if database is open and asks
     * database to create tables
     */
    void createDataBase();

    /**
     * @brief openDataBase
     * Creates SQLite database
     * @return
     * true : if database opens correctly
     * false : if error occurs during opening
     */
    bool openDataBase();

    /**
     * @brief closeDataBase
     * Closes database
     */
    void closeDataBase();

    /**
     * @brief createTable
     * Used on derived classes to create
     * different kind of tables
     */
    virtual void createTable() = 0;

    QSqlDatabase db;
    std::shared_ptr<AnalyticsModel> aModel_ = nullptr;
    std::shared_ptr<ResultModel> rModel_ = nullptr;
    std::shared_ptr<PersonalResultModel> pModel_ = nullptr;

private:
    QString errorMessage_ = "No errors!";
};

#endif // ABSTARCTDATABASE_H
