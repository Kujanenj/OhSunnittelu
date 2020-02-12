#include "datahandler.h"
#include <QDebug>
#include <QStringList>
DataHandler::DataHandler()
{

}

bool DataHandler::formMap(QString& data)
{
   data_=data;
  simpleRead();
  Dissasemply();
  return true;
}

bool DataHandler::simpleRead()
{

    QFile file("testDataParsed.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"fail";
        return false;

    }

    while (!file.atEnd()) {

           QString line = file.readLine();
          data_.append(line);
        }

    return true;
}

void DataHandler::Dissasemply()
{


    QVector<QString> insertionVector;
    QStringList lista=data_.split("$");
    for(int i=0; i<lista.size(); i++){

        insertionVector.append(lista.at(i));
        if(i%12==11 ){

         initialVector_.append(insertionVector);
         insertionVector.clear();
        }

    }
    qDebug()<<initialVector_;





}

void DataHandler::assembleMap(QString config)
{

}
