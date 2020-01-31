#ifndef PARSER_H
#define PARSER_H
#include <QFile>
#include <QDebug>
class Parser
{
public:
    Parser();
    bool fullParse(QString filename);

private:
    bool readFile(QString filename);
    bool parseToTable();
    bool parseTable();
   QByteArray unparsedDataTotal_="";

};

#endif // PARSER_H
