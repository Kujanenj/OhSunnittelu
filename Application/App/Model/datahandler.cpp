#include "datahandler.h"
#include <QDebug>
#include <QStringList>
namespace Model{
DataHandler::DataHandler()
{

}

bool DataHandler::formMap(QString& data)
{
    if(data=="testing"){
      data_=data;
      simpleRead();
      Dissasemply();
      sort(2);
    }

  return true;
}

QVector<QVector<QString> > DataHandler::getSortedDataVector()
{
    return initialVector_;
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






}

void DataHandler::assembleMap(QMap<QString,QString> config)
{








}

void DataHandler::sort(int config)
{
    bool inserted=false;
    int insertPos=0;
    QString fieldValue="";

    QVector<QVector<QString>> tempVec;
    for(auto it=initialVector_.begin(); it!=initialVector_.end(); it++ ){ //go trough all the results. (This is n^2 ;C)
        fieldValue=it->at(config);
        insertPos=0;
        inserted=false;

        //initial insert
        if(tempVec.size()==0){
            tempVec.insert(0,*it);

        }
        else{
         for(auto tempIt=tempVec.begin(); tempIt!=tempVec.end(); tempIt++ ){ //finds the index to place the vector at.
            if(fieldValue>tempIt->at(config))
            {
                insertPos++;
            }
            else{
                tempVec.insert(insertPos,*it);
                inserted=true;
                break;
            }

            }
         if(!inserted){
             tempVec.append(*it);


         }
        }

    }
    initialVector_=tempVec;
    qDebug()<<initialVector_;

}
}
