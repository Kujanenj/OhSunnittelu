#include "personalresultmodel.h"

PersonalResultModel::PersonalResultModel(QObject *parent)
{

}

QHash<int, QByteArray> PersonalResultModel::roleNames() const
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
