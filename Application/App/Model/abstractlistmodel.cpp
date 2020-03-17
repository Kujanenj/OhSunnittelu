#include "abstractlistmodel.h"

AbstractListModel::AbstractListModel(QObject *parent) :
    QSqlQueryModel(parent)
{

}

QVariant AbstractListModel::data(const QModelIndex &index, int role) const
{
    // Define the column number, on the role of number
    int columnId = role - Qt::UserRole - 1;
    // Create the index using a column ID
    QModelIndex modelIndex = this->index(index.row(), columnId);

    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

void AbstractListModel::sortModel(QString command)
{
    this->setQuery(command);
}

void AbstractListModel::updateModel(QString mainTable)
{
  this->setQuery("SELECT * FROM " + mainTable);
}
