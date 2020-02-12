#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <QList>

class DataHandler
{
public:
    DataHandler();

    bool formMap(QString &data);

private:
    /**
     * @brief simpleRead
     * @return testejä varten.
     */
    bool simpleRead();
    /**
     * @brief Dissasemply Dissasembles the given data to be handled later on.
     */
    void Dissasemply();
    /**
     * @brief assembleMap
     * @param config KESKEN
     */
    void assembleMap(QString config);
    QList<QString> template_;
    QString data_="";
    QMultiMap <int,QVector<QString>> initialMap_;
    QVector<QVector<QString>> initialVector_;
};

#endif // DATAHANDLER_H
