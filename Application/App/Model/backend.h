#ifndef BACKEND_H
#define BACKEND_H
#include <QString>
#include <QObject>
#include "Controller/requester.h"
#include <QMap>

/**
 * @brief The Backend class Kommentoikaa kaikki metodit. Laittakaa myös kommentteja tonne koodin puolelle tärkeisiin kohtiin. Jos siis tarvii
 * Try catchit myös mahdollisiin kohtiin mihi voi tulla virheitä
 */

class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

public:
    explicit Backend(QObject *parent = nullptr);

    ~Backend();

    //QML Accessible methods:
    Q_INVOKABLE void searchButtonClicked(QString startYear, QString endYear,
                                         QString distance, QString gender,
                                         QString firstName, QString lastName,
                                         QString place, QString nationality,
                                         QString team);


    //Mikä "text"? Parempi nimi tähän plz
    QString text();
    void setText(const QString &text);

signals:
    void textChanged(const QString & text);

public slots:

private:

    QString mText;
    //void setFieldText(QString value);

    QString fieldText;

    Requester *req;

    std::shared_ptr<Requester> *requester;
};

#endif // BACKEND_H
