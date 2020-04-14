#ifndef PERSONALRESULTSMODEL_H
#define PERSONALRESULTSMODEL_H

#include "abstractlistmodel.h"

/**
 * @brief The PersonalModel class
 * is used to set roles that can be used to create
 * results table on qml
 */
class PersonalResultModel : public AbstractListModel
{
    Q_OBJECT
public:

    /**
     * @brief The resultRoles enum
     * Roles that can be detected from qml
     */
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
    /**
     * @brief roleNames
     * Initializes all roles
     * @return hash-table which contains all roles
     */
    QHash<int, QByteArray> roleNames() const;
};

#endif // PERSONALRESULTSMODEL_H
