#ifndef BACKEND_H
#define BACKEND_H
#include <QString>
#include <QObject>
#include "Controller/requester.h"
#include <QMap>
#include <memory>

/**
 * @brief The Backend class Kommentoikaa kaikki metodit. Laittakaa myös kommentteja tonne koodin puolelle tärkeisiin kohtiin. Jos siis tarvii
 * Try catchit myös mahdollisiin kohtiin mihi voi tulla virheitä
 */

class Backend : public QObject
{
    Q_OBJECT

public:
    explicit Backend(QObject *parent = nullptr);

    ~Backend();

    //QML Accessible methods:
    Q_INVOKABLE void searchButtonClicked(QString startYear, QString endYear,
                                         QString distance, QString gender,
                                         QString firstName, QString lastName,
                                         QString place, QString nationality,
                                         QString team);

signals:

public slots:

private:

    QString fieldText;
    Requester *req;
    std::shared_ptr<Requester> *requester;
};

#endif // BACKEND_H
