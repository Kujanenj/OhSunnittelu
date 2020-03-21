#ifndef LISTMODEL_H
#define LISTMODEL_H

#include "abstractlistmodel.h"

/**
 * @brief The ResultModel class
 * is used to set roles that can be used to create
 * results table on qml
 */
class ResultModel : public AbstractListModel
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

    /**
     * @brief ResultModel
     * Constructor for ResultModel
     * @param parent
     */
    explicit ResultModel(QObject *parent = nullptr);

private:

    /**
     * @brief roleNames
     * Initializes all roles
     * @return hash-table which contains all roles
     */
    QHash<int, QByteArray> roleNames() const;


};

#endif // LISTMODEL_H
