#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QDebug>
#include "requester.h"
#include "../Data/database.h"
#include "calculator.h"
namespace Model {

/**
 * @brief The DataModel class is a facade for all model modules.
 */
class DataModel        
{
public:
    /**
     * @brief DataModel
     * Constructor for datamodel
     * @param database
     */
    DataModel(std::shared_ptr<DataBase> database);

    /**
     * @brief doRequest calls the Requester class to do a html post request
     * @param parameters modifies the behaviour of requester class
     */
    void doRequest(QMap<QString,QString> requesterParameters, QMap<QString,QString> parserParameters);

    /**
     * @brief insertData
     * Used to start insertion to different sql tables
     * @param table
     */
    void insertData(QString table);

    /**
     * @brief sortDataBase Calls the DB  to sort the database according to the command
     * @param command sql instruction
     */
    void sortDataBase(QString sqlcommand);

    /**
     * @brief analytics uses the calculator to calculate all the required fields for analytics
     * @param distances
     * @param years
     */
    void analytics(QVector<QString> distances, std::pair<QString, QString> years);

    /**
     * @brief getAnalyticsVector
     * @return
     */
    QVector<QVector<QString>> getAnalyticsVector();

    /**
     * @brief searchDataBase calls the database search based on the sql command
     * @param sqlCommand
     * @return vector of all results matching the criteria
     */
    QVector<QVector<QString>> searchDataBase(QString sqlCommand);
    /*!
     * \brief getPercanteges returns percentages of corrosponding index field
     * \param sqlCommand "SELECT * FROM results Where X
     * \param index the result field index. E.g: index number 9 is countries
     * \return <Key, percantage>
     */
    QVector<std::pair<QString, float> > getPercanteges(QString sqlCommand, int index);
    /*!
     * \brief timeToFloat
     * \param time
     * \return time as a float number
     */
    float timeToFloat(QString time);
    QVector<std::pair<QString,QString>> getBestTeams(QString sqlCommand, int amount, QString year, QString distance);
private:
    /**
     * @brief doParse Calls the parses to parse the html data
     * @param config modifies the behaviour of the parser
     */
    void doParse(QMap<QString,QString> config);



    std::shared_ptr<Model::Requester> req;
    std::shared_ptr<Model::Parser> parser;
    std::shared_ptr<DataBase> database_;
    std::shared_ptr<Calculator> calc_;

    QVector<std::pair<QString,QString>> bestTeams_;
    QVector<QString> teamNames_;
    QVector<std::pair<QString,float>> countries_;
    QVector<QVector<QString>> analyticsFULL_; //insertion vector to analytics
    QString data_="";
    QVector<QVector<QString>> listedData_;

};

} // Namespace Model

#endif // DATAMODEL_H
