#include "analyticsmodel.h"
#include "Data/database.h"

AnalyticsModel::AnalyticsModel(QObject *parent) :
    QSqlQueryModel(parent)
{
    this->updateModel();
}

QVariant AnalyticsModel::data(const QModelIndex & index, int role) const
{
    // Define the column number, on the role of number
    int columnId = role - Qt::UserRole - 1;
    // Create the index using a column ID
    QModelIndex modelIndex = this->index(index.row(), columnId);

    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

QHash<int, QByteArray> AnalyticsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[DistanceRole] = "distance";
    roles[AvgspeedRole] = "avgspeed";
    roles[ParticipantsRole] = "participants";
    roles[FastesttimeRole] = "fastesttime";
    roles[SlowesttimeRole] = "slowesttime";
    roles[WinnerRole] = "winner";
    roles[SecondRole] = "second";
    roles[ThirdRole] = "third";
    return roles;
}

void AnalyticsModel::updateModel()
{

    qDebug() << "Updating model";
    // The update is performed SQL-queries to the database
    this->setQuery("SELECT *, " TABLE_YEAR ", " TABLE_DIST ", " TABLE_TIME ", " TABLE_PLACE ", " TABLE_PLACEM ", " TABLE_PLACEN ", " TABLE_GENDER ", " TABLE_SFNAME ", " TABLE_CITY ", " TABLE_NATIONALITY ", " TABLE_AGE ", " TABLE_TEAM "  FROM " TABLE);
}
