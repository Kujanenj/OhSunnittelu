#include "parser.h"


/*!
 * \brief Parser::Parser Vaatii seuraavia asioita:
 * Kaikkea
 * Lue tiedostostosta?
 * filtteröi kaikki paska
 * Tallenna johonki? Vai lähetä suoraa mainille? (Tai managerille tai jonnekki)
 * Funktiota ->
 * read file
 * parse
 * error checkit
 * kirjoita logiin? vai lähetä error viestit mainiin joka kirjoittaa ne logii?
 *
 *
 */
Parser::Parser()
{

}

bool Parser::fullParse(QString filename)
{
    readFile(filename);
    parseToTable();
    parseTable();
}

bool Parser::parseToTable()
{

    int tableStartIndex=unparsedDataTotal_.indexOf("</thead><tbody>");
    unparsedDataTotal_=unparsedDataTotal_.remove(0,tableStartIndex);
       int tableEndindex = unparsedDataTotal_.indexOf("</table><div");
    unparsedDataTotal_=unparsedDataTotal_.remove(tableEndindex,unparsedDataTotal_.size()-tableEndindex);
    qDebug()<<unparsedDataTotal_;
    return true;
}

bool Parser::parseTable()
{

}

bool Parser::readFile(QString filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"Error message";
            return false;
    }

    while (!file.atEnd()) {
            QByteArray line = file.readLine();
          unparsedDataTotal_.append(line);
        }
    return true;
}
