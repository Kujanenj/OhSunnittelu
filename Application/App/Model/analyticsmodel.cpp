#include "analyticsmodel.h"
#include "Data/database.h"

AnalyticsModel::AnalyticsModel(QObject *parent) :
   AbstractListModel(parent)
{

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

