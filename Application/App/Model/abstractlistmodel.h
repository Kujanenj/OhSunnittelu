#ifndef ABSTRACTLISTMODEL_H
#define ABSTRACTLISTMODEL_H

#include <QSqlQueryModel>

class AbstractListModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    AbstractListModel(QObject *parent = nullptr);

    virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    virtual void sortModel(QString command);
public slots:
    void updateModel(QString mainTable);
protected:
    virtual QHash<int, QByteArray> roleNames() const = 0;
};

#endif // ABSTRACTLISTMODEL_H
