#ifndef ANALYTICSMODEL_H
#define ANALYTICSMODEL_H

#include "abstractlistmodel.h"

/**
 * @brief The AnalyticsModel class
 * is used to set roles that can be used to create
 * analytics table on qml
 */
class AnalyticsModel : public AbstractListModel
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
        AvgtimeRole,
        ParticipantsRole,
        FastesttimeRole,
        SlowesttimeRole,
        WinnerRole,
        SecondRole,
        ThirdRole,
        bestteamRole,
        winnerSpeedRole
    };

    /**
     * @brief AnalyticsModel
     * Constructor for AnalyticsModel
     * @param parent
     */
    explicit AnalyticsModel(QObject *parent = nullptr);

private:

    /**
     * @brief roleNames
     * Initializes all roles
     * @return hash-table which contains all roles
     */
    QHash<int, QByteArray> roleNames() const;
};

#endif // ANALYTICSMODEL_H
