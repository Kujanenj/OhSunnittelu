#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QObject>
#include <QSqlQueryModel>

class ListModel : public QSqlQueryModel
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

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    void sortListModel(QString command);
private:
    QHash<int, QByteArray> roleNames() const;

public slots:
    void updateModel();

};

#endif // LISTMODEL_H
