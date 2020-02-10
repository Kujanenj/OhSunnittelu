#include "parser.h"



Parser::Parser(QMap<QString, QString> config, QString& dataToParse) : unparsedDataTotal_(dataToParse)
{
    config_ = config;

}

QString Parser::fullParse()
{
    try {

        readFile();
        parseToTable();
        parseTable();
    } catch (QString msg) {
         std::move(msg);
    }
    qDebug()<<returnMessage_;
    return returnMessage_;
}

void Parser::parseToTable()
{

    qDebug()<<"String Size "<<unparsedDataTotal_.size();
    int tableStartIndex=unparsedDataTotal_.indexOf(config_["tableStart"]);
    unparsedDataTotal_=unparsedDataTotal_.remove(0,tableStartIndex); // remove extra stuff from start
    qDebug()<<"String Size "<<unparsedDataTotal_.size();
        int tableEndindex = unparsedDataTotal_.indexOf(config_["tableEnd"]);

    unparsedDataTotal_=unparsedDataTotal_.remove(tableEndindex,unparsedDataTotal_.size()-tableEndindex); //remove extra stuff from end
    qDebug()<<"String Size "<<unparsedDataTotal_.size();


    if(tableEndindex ==-1 || tableStartIndex ==-1){
        returnMessage_="ERROR I am unable to find table. Tried to search for" + config_["tableStart"]+"(start of table)" +
                " and "+ config_["tableEnd"] + "(end of table)";

        throw returnMessage_;
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
   parsedData.replace("</td>>",";"); //replace delimeter
   parsedData.remove(0,1); //extra char at start
   parsedData.chop(5); //extra chars at end

   unparsedDataTotal_=parsedData;


    if(config_["fileToWrite"]!="false"){
    QFile file("../../Application/Data/DataOut.txt");
    if(file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
        stream<<parsedData;
    }}
}

void Parser::readFile()
{
    qDebug() << "Aletaan lukemaan data.txt filua t parseri";

    if(config_["fileToRead"]=="false"){
        qDebug()<<"Häähää ei luettukaa";
        return;
    }
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

