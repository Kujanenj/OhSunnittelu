#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QDebug>
#include "requester.h"
#include "../Data/database.h"
#include "calculator.h"
namespace Model {


class DataModel
{
public:
    DataModel(std::shared_ptr<DataBase> database);
    void doRequest(QMap<QString,QString> parameters);
    void doParse(QMap<QString,QString> config);
    void insertData();
    void sortDataBase(QString command);
    void analytics(QVector<QString> distances);

    QVector<QVector<QString>> searchDataBase(QString sqlCommand);

private:
    std::shared_ptr<Model::Requester> req;
    std::shared_ptr<Model::Parser> parser;
    std::shared_ptr<DataBase> database_;
    std::shared_ptr<Calculator> calc_;

    QString data_="";
    QVector<QVector<QString>> listedData_;
    QVector<QString> getTeamNames();

};
}
#endif // DATAMODEL_H
