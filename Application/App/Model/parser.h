#ifndef PARSER_H
#define PARSER_H
#include <QFile>
#include <QDebug>
#include <QMap>
#include <QDir>
/*!
 * \brief The Parser class parses the finlandiahiihtoSivu. Modifies dataToParse. Can be provided with a txt file if nessecary.
 *
 *
 */
namespace Model{
class Parser
{
public:

    /**
     * @brief Parser default constructor
     * @param config  a map containing all the required configs to make a parse
     * {{"fileToRead", "../../Application/Data/data.txt"},
     {"fileToWrite", "../../Application/Data/dataOut,txt"},
     {"tableStart", "</thead><tbody>"},
     {"tableEnd", "</table><div"},
     {"tableCellLeft", "7pt;\">"},
     {"tableCellRight","<"}};
     */
    Parser();

    ~Parser();

    /**
    * @brief fullParse calls the other methods required for parsing the data
    * @param config contains information about how the parse will be preformed. See above
    * @param dataToParse duh
    */
   void fullParse(QMap<QString,QString> config, QString dataToParse);

   /**
    * @brief getListedData
    * @return listedData_ vector that contains all user result
    * parameters
    */
   QVector<QVector<QString>> getListedData();

   /**
    * @brief clearListedData
    * Used to clear old listedData_ vector
    */
   void clearListedData();
   /*!
    * \brief getTeamNames
    * \return
    */
   QVector<QString> getTeamNames();
   /*!
    * \brief clearTeams
    */
   void clearTeams();

private:

    /**
     * @brief optionally reads a txt file containing the data

     */
   void readFile();

    /**
     * @brief parseToTable parses the file down to just the table elements.
     */
    void parseToTable();

    /**
     * @brief parseTable does the final parsing, and writes the complete data to a txt file if requested.
     */
    void parseTable();
    /**
     * @brief formListedData creates a fomatted list of the results
     */
    void formListedData();



    QString unparsedDataTotal_;

    QMap<QString, QString> config_;
    QString returnMessage_ = "Parse was successful";

    QVector<QVector<QString>> listedData_;

    QVector<QString> valid_teams;
};
}
#endif // PARSER_H
