#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <QString>
#include <QObject>
#include "Model/requester.h"

#include <QMap>
#include <memory>


namespace Controller {


/**
 * @brief The Datamanager class. Controls data between view and model
 */

class Datamanager : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Datamanager constructor
     * @param parent null pointer to QObject
     */
    explicit Datamanager(QObject *parent = nullptr);

    /**
      * @brief Datamanager destructor
      */
    ~Datamanager();

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
                                         QString distance, QString gender, QString ageSeries,
                                         QString firstName, QString lastName,
                                         QString place, QString nationality,
                                         QString team);

signals:

public slots:

private:
    //Requester *req;
    std::shared_ptr<Model::Requester> req;
    std::shared_ptr<Model::Parser> parser;
    QString data_="contains nothing yet ;)";

    QMap<QString,QString> parserConfig_ = {{"fileToRead", "false"}, //false = "älä lue mitää"
                                     {"fileToWrite", "false"},//false = "älä kirjota mitää"
                                     {"tableStart", "</thead><tbody>"},
                                     {"tableEnd", "</table><div"},
                                     {"tableCellLeft", "7pt;\">"},
                                     {"tableCellRight","</td>"}};
};
}

#endif // DATAMANAGER_H
