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
    void doRequest(QMap<QString,QString> parameters);

    /**
     * @brief doParse Calls the parses to parse the html data
     * @param config modifies the behaviour of the parser
     */
    void doParse(QMap<QString,QString> config);

    /**
     * @brief TODO: insertData Nää pitää muuttaa koska vituillaan. Ei oo järkee ettei oo mitää parametrei ja sit nää pitää yhistää.
     *  minä hoidan.
     */
    void insertData(QString personalSearch);

    void insertAnalyticsData();

    /**
     * @brief sortDataBase Calls the DB  to sort the database according to the command
     * @param command sql instruction
     */
    void sortDataBase(QString command);

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

    /**
     * @brief getTeamNames returns all unique team names, exculding blanks
     * @return
     */
    QVector<QString> getTeamNames();


    QVector<std::pair<QString, float> > getCountries(QString sqlCommand);
private:
    std::shared_ptr<Model::Requester> req;
    std::shared_ptr<Model::Parser> parser;
    std::shared_ptr<DataBase> database_;
    std::shared_ptr<Calculator> calc_;

    QVector<QString> teamNames_;
    QVector<std::pair<QString,float>> countries_;
    QVector<QVector<QString>> analyticsFULL_; //insertion vector to analytics
    QString data_="";
    QVector<QVector<QString>> listedData_;

};

} // Namespace Model

#endif // DATAMODEL_H
