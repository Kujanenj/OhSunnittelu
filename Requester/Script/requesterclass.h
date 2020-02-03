#ifndef REQUESTERCLASS_H
#define REQUESTERCLASS_H

#include <QObject>

class requesterClass : public QObject
{
    Q_OBJECT
public:
    explicit requesterClass(QObject *parent = nullptr);

signals:

public slots:
};

#endif // REQUESTERCLASS_H
