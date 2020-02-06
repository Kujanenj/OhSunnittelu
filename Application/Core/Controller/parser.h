#ifndef PARSER_H
#define PARSER_H
#include <QFile>
#include <QDebug>
#include <QMap>
#include <QDir>
/*!
 * \brief The Parser class parses the finlandiahiihtoSivu. Writes parsed table data a txt file.
 *
 */
class Parser
{
public:

    /**
     * \brief Parser default constructor
     * \param config  a map containing all the required configs to make a parse
     * {{"fileToRead", "../../Data/data.txt"},
     {"fileToWrite", "../../Data/dataOut"},
     {"tableStart", "</thead><tbody>"},
     {"tableEnd", "</table><div"},
     {"tableCellLeft", "7pt;\">"},
     {"tableCellRight","<"}};
     */
    Parser(QMap<QString,QString> config, QString dataToParse);

    /**
     * \brief fullParse calls all other private methods

     * \return The return msg of the parse. Success or fail
     */
    QString fullParse();

private:

    /**
     * \brief readFile saves filedata to unparsedDataTotal

     */
   void readFile();

    /**
     * \brief parseToTable parses the file down to just the table elements.
     */
    void parseToTable();

    /**
     * \brief parseTable does the final parsing, and writes the complete data to a txt file.
     */
    void parseTable();

    QString unparsedDataTotal_ = "";
    QString parsedData = "";
    QMap <QString, QString> config_;
    QString returnMessage_ = ";)";

};

#endif // PARSER_H
