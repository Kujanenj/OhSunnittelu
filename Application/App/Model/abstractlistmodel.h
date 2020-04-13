#ifndef ABSTRACTLISTMODEL_H
#define ABSTRACTLISTMODEL_H

#include <QSqlQueryModel>
/*!
 * \brief The AbstractListModel class is baseclass for all models for displaying SQL
 */
class AbstractListModel : public QSqlQueryModel
{
    Q_OBJECT
public:

    /**
     * @brief AbstractListModel
     * Constructor for AbstractListModel
     * @param parent
     */
    AbstractListModel(QObject *parent = nullptr);

    /**
     * @brief data
     * Used on background to update specific role on specific
     * row to database
     * @param index
     * @param role
     * @return
     */
    virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    /**
     * @brief sortModel
     * Used to sort data on sql
     * @param command : contains command to data that must be sorted
     */
    virtual void sortModel(QString command);

public slots:

    /**
     * @brief updateModel
     * Updates specific table
     * @param mainTable : table to update
     */
    void updateModel(QString mainTable);

protected:

    /**
     * @brief roleNames
     * Pure-virtual method that is used on derived
     * classes to set roles for qml
     * @return
     */
    virtual QHash<int, QByteArray> roleNames() const = 0;
};

#endif // ABSTRACTLISTMODEL_H
