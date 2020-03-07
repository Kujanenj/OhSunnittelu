#ifndef ANALYTICSMODEL_H
#define ANALYTICSMODEL_H

#include <QObject>
#include <QSqlQueryModel>

class AnalyticsModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    enum resultRoles {
        IdRole = Qt::UserRole + 1,
        DistanceRole,
        AvgspeedRole,
        ParticipantsRole,
        FastesttimeRole,
        SlowesttimeRole,
        WinnerRole,
        SecondRole,
        ThirdRole
    };

    explicit AnalyticsModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    void sortListModel(QString sortBy, QString direction);
private:
    QHash<int, QByteArray> roleNames() const;

public slots:
    void updateModel();

};

#endif // ANALYTICSMODEL_H
