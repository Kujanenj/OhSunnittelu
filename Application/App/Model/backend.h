#ifndef BACKEND_H
#define BACKEND_H
#include <QString>
#include <QObject>
#include "Controller/requester.h"

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
    Q_INVOKABLE void searchButtonClicked();


    //Mikä "text"? Parempi nimi tähän plz
    const QString text();
    void setText(const QString &text);

signals:
    void textChanged(const QString & text);

public slots:

private:
    QString mText;
    //void setFieldText(QString value);

    QString fieldText;

    Requester *req;
};

#endif // BACKEND_H
