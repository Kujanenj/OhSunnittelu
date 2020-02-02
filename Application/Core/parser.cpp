#include "parser.h"



Parser::Parser(QMap<QString, QString> config)
{
config_=config;
}

bool Parser::fullParse()
{
    readFile();
    parseToTable();
    parseTable();
    return true;
}

bool Parser::parseToTable()
{
    qDebug()<<"String Size "<<unparsedDataTotal_.size();
    int tableStartIndex=unparsedDataTotal_.indexOf(config_["tableStart"]);
    unparsedDataTotal_=unparsedDataTotal_.remove(0,tableStartIndex); // remove extra stuff from start
    qDebug()<<"String Size "<<unparsedDataTotal_.size();
       int tableEndindex = unparsedDataTotal_.indexOf(config_["tableEnd"]);
    unparsedDataTotal_=unparsedDataTotal_.remove(tableEndindex,unparsedDataTotal_.size()-tableEndindex); //remove extra stuff from end
    qDebug()<<"String Size "<<unparsedDataTotal_.size();
    return true;
}

bool Parser::parseTable()
{
   int left=0;
   int right=0;
   for(int i = 0; i<=unparsedDataTotal_.length();i++){ //search for these occurencses, and save the stuff in between.
       left=unparsedDataTotal_.indexOf(config_["tableCellLeft"],right);
       right=unparsedDataTotal_.indexOf("tableCellRight",left);
       parsedData=parsedData.append(unparsedDataTotal_.mid(left+5,(right-left)));
   }
   parsedData.replace("</td>>",";"); //replace delimeter
   parsedData.remove(0,1); //extra char at start
   parsedData.chop(5); //extra chars at end



    QFile file("fileToWrite");
    if(file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
        stream<<parsedData;
    }
    return true;
}

bool Parser::readFile()
{
    QFile file(config_["fileToRead"]);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Error message";
            return false;
    }

    while (!file.atEnd()) {

           QString line = file.readLine();
          unparsedDataTotal_.append(line);
        }

    return true;
}
