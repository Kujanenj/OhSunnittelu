#ifndef LISTMODEL_H
#define LISTMODEL_H


#include "abstractlistmodel.h"

class ListModel : public AbstractListModel
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

    explicit ListModel(QObject *parent = nullptr);
private:
    QHash<int, QByteArray> roleNames() const;


};

#endif // LISTMODEL_H
