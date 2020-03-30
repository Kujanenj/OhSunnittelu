#include "parser.h"

namespace Model{

Parser::Parser()
{
    qDebug() << "pareseri luotu";

}

Parser::~Parser()
{
    qDebug() << "Parser tuhottu";
}

void Parser::fullParse(QMap<QString,QString> config, QString dataToParse)
{
    config_ = config;
    unparsedDataTotal_ = dataToParse;
    try {
        if(config_["fileToRead"]=="true"){
            readFile();
        }
        parseToTable();
        parseTable();
        formListedData();
    } catch (QString msg) {
         qDebug() << msg;
         return;
    }
}

QVector<QVector<QString> > Parser::getListedData()
{
    return listedData_;
}

void Parser::clearListedData()
{
    listedData_.clear();
}

void Parser::readFile()
{

    qDebug()<<"luettiin tiedosto parsesrissa, vissiin testailemassa?? ;)";
    QFile file(config_["fileToRead"]);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        returnMessage_="ERROR file to read not found, i am trying to look from "+ QDir::currentPath()+ " + "+ config_["fileToRead"];

        throw returnMessage_;
    }

    while (!file.atEnd()) {

           QString line = file.readLine();
          unparsedDataTotal_.append(line);
        }
}

void Parser::parseToTable()
{

    qDebug()<<"String Size "<<unparsedDataTotal_.size();
    int tableStartIndex=unparsedDataTotal_.indexOf(config_["tableStart"]);
    int tableEndindex = unparsedDataTotal_.indexOf(config_["tableEnd"]);


    if(tableEndindex ==-1 || tableStartIndex ==-1){
        returnMessage_="ERROR I am unable to find table. Tried to search for" + config_["tableStart"]+"(start of table)" +
                " and "+ config_["tableEnd"] + "(end of table)";

        throw returnMessage_;
    }
    else{
        unparsedDataTotal_=unparsedDataTotal_.remove(0,tableStartIndex); // remove extra stuff from start
        unparsedDataTotal_=unparsedDataTotal_.remove(tableEndindex,unparsedDataTotal_.size()-tableEndindex); //remove extra stuff from end
        qDebug()<<"String Size "<<unparsedDataTotal_.size();
    }


}

void Parser::parseTable()
{
   QString parsedData = "";
   int left=0;
   int right=0;
   for(int i = 0; i<=unparsedDataTotal_.length();i++){ //search for these occurencses, and save the stuff in between.
       left=unparsedDataTotal_.indexOf(config_["tableCellLeft"],right);

       right=unparsedDataTotal_.indexOf(config_["tableCellRight"],left);
       parsedData=parsedData.append(unparsedDataTotal_.mid(left+5,(right-left)));
   }
   if(left == 0 || right ==0){
       throw "ERROR parsing the table";
   }

   parsedData.replace("</td>>","$"); //replace delimeter
   parsedData.remove(0,1); //extra char at start
   parsedData.chop(5); //extra chars at end


   parsedData.replace("&nbsp;", "-");

   unparsedDataTotal_=parsedData;


    if(config_["fileToWrite"]!="false"){
    QFile file(config_["fileToWrite"]);
    if(file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
        stream<<parsedData;
    }}

}




void Parser::formListedData()
{


    QVector<QString> insertionVector;
    QStringList lista=unparsedDataTotal_.split("$");
    int total_results = 0;

    for(int i=0; i<lista.size(); i++){

        insertionVector.append(lista.at(i));
        if(i%12==11 ){

            //inserti
             if(insertionVector[2].count(":")>1){
            if(insertionVector.at(3)>="1"){


            if(insertionVector.at(2).length()<8){
                insertionVector[2]=insertionVector.at(2)+".00";
            }
         listedData_.append(insertionVector);
         total_results += 1;
          }}
         insertionVector.clear();


        }

    }

    if (lista.size() == 1){

    qDebug()<< "No results found";

    }

    else{
        qDebug() << "Total results:" << total_results;
    }
}
}
