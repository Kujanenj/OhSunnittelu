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
    roles[bestteamRole] = "bestteam";
    return roles;
}

void AnalyticsModel::updateModel()
{

    qDebug() << "Updating model";
    // The update is performed SQL-queries to the database
    this->setQuery("SELECT *, " TABLE_2_DIST ", " TABLE_2_AVGSPEED ", " TABLE_2_PARTICIPANTS ", " TABLE_2_FASTESTTIME ", " TABLE_2_SLOWESTTIME ", " TABLE_2_WINNER ", " TABLE_2_SECOND ", " TABLE_2_THIRD ", " TABLE_2_BEST_TIME " FROM " TABLE_2);
}
