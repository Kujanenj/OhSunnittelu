#ifndef PERSONALRESULTSMODEL_H
#define PERSONALRESULTSMODEL_H

#include "abstractlistmodel.h"

class PersonalResultModel : public AbstractListModel
{
    Q_OBJECT
public:

    enum resultRoles {
        IdRole = Qt::UserRole + 1,
        YearRole,
        DistanceRole,
        TimeRole,
        PlaceRole,
        PlaceMRole,
        PlaceNRole,
        GenderRole,
        SFNameRole,
        CityRole,
        NationalityRole,
        AgeRole,
        TeamRole
    };

    explicit PersonalResultModel(QObject *parent = nullptr);

private:
    QHash<int, QByteArray> roleNames() const;
};

#endif // PERSONALRESULTSMODEL_H
