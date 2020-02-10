#ifndef PARSER_H
#define PARSER_H
#include <QFile>
#include <QDebug>
#include <QMap>
#include <QDir>
/*!
 * \brief The Parser class parses the finlandiahiihtoSivu. Modifies dataToParse. Can be provided with a txt file if nessecary
 *
 */
class Parser
{
public:

    /**
     * \brief Parser default constructor
     * \param config  a map containing all the required configs to make a parse
     * {{"fileToRead", "../../Application/Data/data.txt"},
     {"fileToWrite", "../../Application/Data/dataOut,txt"},
     {"tableStart", "</thead><tbody>"},
     {"tableEnd", "</table><div"},
     {"tableCellLeft", "7pt;\">"},
     {"tableCellRight","<"}};
     */
    Parser();

    /**
     * \brief fullParse calls all other private methods

     * \return The return msg of the parse. Success or fail
     */
    QString fullParse(QMap<QString,QString> config, QString& dataToParse);

private:

    /**
     * \brief optionally reads a txt file containing the data

     */
   void readFile();

    /**
     * \brief parseToTable parses the file down to just the table elements.
     */
    void parseToTable();

    /**
     * \brief parseTable does the final parsing, and writes the complete data to a txt file if requested.
     */
    void parseTable();

    QString unparsedDataTotal_;

    QMap <QString, QString> config_;
    QString returnMessage_ = "Parse onnistui";

};

#endif // PARSER_H
