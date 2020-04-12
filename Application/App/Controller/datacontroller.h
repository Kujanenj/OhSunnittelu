#ifndef DATACONTROLLER_H
#define DATACONTROLLER_H
#include <QString>
#include <QVector>
#include <QObject>
#include "Model/requester.h"
#include "Data/database.h"
#include "../Model/datamodel.h"
#include <algorithm>
#include <QMap>
#include <memory>


namespace Controller {


/**
 * @brief The DataController class. Controls data between view and model
 */

class DataController : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief DataController constructor
     * @param parent null pointer to QObject
     */
    explicit DataController(std::shared_ptr<Model::DataModel> model, QObject *parent = nullptr);

    /**
      * @brief DataController destructor
      */
    ~DataController();

    /**
      * @brief Q_INVOKABLE type function that is called from QML when search button is clicked.
      * @param startYear search start year option
      * @param endYear search ending year option
      * @param distance search distance option
      * @param gender search gender option
      * @param ageSeries search ageseries option
      * @param firstName search first name option
      * @param lastName search last name option
      * @param place search place option
      * @param nationality search nationality option
      * @param team search team option
      */
    Q_INVOKABLE void searchButtonClicked(QString startYear, QString endYear,
                                         QVector<QString> distance, QString gender, QVector<QString> ages,
                                         QString firstName, QString lastName,
                                         QString place, QString nationality,
                                         QString team, QString personalSearch);
    Q_INVOKABLE void sortButtonClicked(QString selectedField, QString upperBound, QString lowerBound, QString rankSilder);


    Q_INVOKABLE QVector<int> getGraphValues(QString graphtype, QString year, QString distance);
    Q_INVOKABLE QVector<QString> getGraphTypes(QString graphtype, QString year, QString distance);
    Q_INVOKABLE QStringList getYears();
    Q_INVOKABLE QStringList getDistances(QString year);

    Q_INVOKABLE void updateDistances();

    Q_INVOKABLE QStringList getDist();
signals:

public slots:

private:
    //Requester *req;
    std::shared_ptr<DataBase> database_;

    std::shared_ptr<Model::DataModel> dataModel_;
    QStringList years_;

    QMap<QString,QString> parserConfig_ = {{"fileToRead", "false"}, //false = "älä lue mitää"
                                     {"fileToWrite", "false"},//false = "älä kirjota mitää"
                                     {"tableStart", "</thead><tbody>"},
                                     {"tableEnd", "</table><div"},
                                     {"tableCellLeft", "7pt;\">"},
                                     {"tableCellRight","</td>"}};

    QStringList distances_;



};
}

#endif // DATACONTROLLER_H
