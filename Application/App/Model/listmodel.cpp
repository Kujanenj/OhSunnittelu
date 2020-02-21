#include "listmodel.h"
#include "Data/database.h"

ListModel::ListModel(QObject *parent) :
    QSqlQueryModel(parent)
{
    this->updateModel();
}

QVariant ListModel::data(const QModelIndex & index, int role) const {

    // Define the column number, on the role of number
    int columnId = role - Qt::UserRole - 1;
    // Create the index using a column ID
    QModelIndex modelIndex = this->index(index.row(), columnId);

    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

void ListModel::sortListModel(QString sortBy, QString direction)
{
    this->setQuery("SELECT * FROM Results ORDER BY " +sortBy+" "+direction);
}

QHash<int, QByteArray> ListModel::roleNames() const
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

void ListModel::updateModel()
{

    qDebug() << "Updating model";
    // The update is performed SQL-queries to the database
    this->setQuery("SELECT *, " TABLE_YEAR ", " TABLE_DIST ", " TABLE_TIME ", " TABLE_PLACE ", " TABLE_PLACEM ", " TABLE_PLACEN ", " TABLE_GENDER ", " TABLE_SFNAME ", " TABLE_CITY ", " TABLE_NATIONALITY ", " TABLE_AGE ", " TABLE_TEAM "  FROM " TABLE);
}

