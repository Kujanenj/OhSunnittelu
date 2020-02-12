#include "datahandler.h"
#include <QDebug>
DataHandler::DataHandler()
{

}

bool DataHandler::formMap()
{
    QString datatest="";
 return simpleRead(datatest);
}

bool DataHandler::simpleRead(QString data)
{

    QFile file("testDataParsed.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"fail";
        return false;

    }

    while (!file.atEnd()) {

           QString line = file.readLine();
          data.append(line);
        }
    qDebug()<<data;
    return true;
}
