#ifndef ANALYTICSMODEL_H
#define ANALYTICSMODEL_H

#include "abstractlistmodel.h"

class AnalyticsModel : public AbstractListModel
{
    Q_OBJECT
public:
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
        bestteamRole
    };

    explicit AnalyticsModel(QObject *parent = nullptr);


private:
    QHash<int, QByteArray> roleNames() const;


};

#endif // ANALYTICSMODEL_H
