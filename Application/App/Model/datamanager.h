#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <QString>
#include <QObject>
#include "Controller/requester.h"
#include <QMap>
#include <memory>

/**
 * @brief The Datamanager class
 * Kommentoikaa kaikki metodit. Laittakaa myös kommentteja tonne koodin puolelle tärkeisiin kohtiin. Jos siis tarvii
 * Try catchit myös mahdollisiin kohtiin mihi voi tulla virheitä
 */

class Datamanager : public QObject
{
    Q_OBJECT

public:
    explicit Datamanager(QObject *parent = nullptr);

    ~Datamanager();

    //QML Accessible methods:
    Q_INVOKABLE void searchButtonClicked(QString startYear, QString endYear,
                                         QString distance, QString gender, QString ageSeries,
                                         QString firstName, QString lastName,
                                         QString place, QString nationality,
                                         QString team);
    Q_INVOKABLE QString getMastiff();
signals:

public slots:

private:
    //Requester *req;
    std::shared_ptr<Requester> req;
};

#endif // DATAMANAGER_H
