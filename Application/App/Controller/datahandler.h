#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <QList>

class DataHandler
{
public:
    DataHandler();
    bool formMap();
private:
    bool simpleRead(QString data);


    QList<QString> template_;
};

#endif // DATAHANDLER_H
