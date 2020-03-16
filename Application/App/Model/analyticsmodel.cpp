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
    roles[YearRole] = "year";
    roles[DistanceRole] = "distance";
    roles[AvgtimeRole] = "avgtime";
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

    qDebug() << "Updating analytics model";
    this->setQuery("SELECT *, " TABLE_2_YEAR ", " TABLE_2_DIST ", " TABLE_2_AVGTIME ", " TABLE_2_PARTICIPANTS ", " TABLE_2_FASTESTTIME ", " TABLE_2_SLOWESTTIME ", " TABLE_2_WINNER ", " TABLE_2_SECOND ", " TABLE_2_THIRD ", " TABLE_2_BEST_TEAM " FROM " TABLE_2);
}
