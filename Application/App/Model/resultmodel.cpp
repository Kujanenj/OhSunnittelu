#include "resultmodel.h"
#include "Data/database.h"

ResultModel::ResultModel(QObject *parent) :
    AbstractListModel(parent)
{

}

QVariantList ResultModel::getData(QString row)
{
    qDebug() << "Row is: " << row;

    int columnID_name = SFNameRole - Qt::UserRole - 1;
    int columnID_city = CityRole - Qt::UserRole - 1;

    QModelIndex modelIndex_name = this->index(row.toInt(), columnID_name);
    QModelIndex modelIndex_city = this->index(row.toInt(), columnID_city);

    QStringList name = QSqlQueryModel::data(modelIndex_name, Qt::DisplayRole).toString().split(" ");
    QString sname = name.at(0);
    QString fname = name.at(1);

    QString city = QSqlQueryModel::data(modelIndex_city, Qt::DisplayRole).toString();

    QVariantList parameters;
    // QVector<QString> parameters;

    parameters.push_back(sname);
    parameters.push_back(fname);
    parameters.push_back(city);

    qDebug() << sname;
    qDebug() << fname;
    qDebug() << city;

    return parameters;
}

QHash<int, QByteArray> ResultModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[YearRole] = "year";
    roles[DistanceRole] = "distance";
    roles[TimeRole] = "time";
    roles[PlaceRole] = "place";
    roles[PlaceMRole] = "placem";
    roles[PlaceNRole] = "placen";
    roles[GenderRole] = "gender";
    roles[SFNameRole] = "sfname";
    roles[CityRole] = "city";
    roles[NationalityRole] = "nationality";
    roles[AgeRole] = "age";
    roles[TeamRole] = "team";
    return roles;
}



