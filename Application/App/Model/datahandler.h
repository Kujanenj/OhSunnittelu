#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <QList>
#include <QMultiMap>
#include <QVector>
#include <QFile>
namespace Model {


/**
 * @brief The DataHandler class forms the parsed data to the required form. This will include sorting the data, for example, alphabeticcaly.
 * Unfinished
 */
class DataHandler
{
public:
    DataHandler();
    /**
     * @brief formMap PLACEHOLDER METHOD
     * @param data
     * @return
     */
    bool formMap(QString &data);
   QVector<QVector<QString>> getSortedDataVector();
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
    void assembleMap(QMap<QString, QString> config);
    /*!
     * \brief sort Tällä voi sorttaa sen initial vectorin UTF-8:n mukaan aakkosjärjestyksee configin mukaan. int config=vektorin index. Esim conifg 7 on nimen mukaan.
     * \param config
     */
    void sort(int config);



    QList<QString> template_;
    QString data_="";
    QMultiMap <int,QVector<QString>> initialMap_;
    QVector<QVector<QString>> initialVector_;
};
}
#endif // DATAHANDLER_H
