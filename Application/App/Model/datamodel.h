#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QDebug>
#include "requester.h"
#include "../Data/database.h"
namespace Model {


class DataModel
{
public:
    DataModel(std::shared_ptr<DataBase> database);
    void doRequest(QMap<QString,QString> parameters);
    void doParse(QMap<QString,QString> config);
    void insertData();
    void sortDataBase(QString field);
private:
    std::shared_ptr<Model::Requester> req;
    std::shared_ptr<Model::Parser> parser;
    std::shared_ptr<DataBase> database_;

    QString data_="";
    QVector<QVector<QString>> listedData_;

};
}
#endif // DATAMODEL_H