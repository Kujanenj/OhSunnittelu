#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <QString>
#include <QObject>
#include "Model/requester.h"
#include "Model/datahandler.h"
#include <QMap>
#include <memory>

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
    std::shared_ptr<Requester> req;
};

#endif // DATAMANAGER_H
