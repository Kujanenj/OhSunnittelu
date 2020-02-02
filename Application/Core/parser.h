#ifndef PARSER_H
#define PARSER_H
#include <QFile>
#include <QDebug>
#include <QMap>
/*!
 * \brief The Parser class parses the finlandiahiihtoSivu. Writes parsed table data a txt file.
 * TODO: kommenttia. Kaikki turvacheckit puuttuu ihan kokonaan. Jos kusee jotenki niin ei saada ikinä tietää.
 * Vois kans lisätä jonku getin joka palauttaa ton parsedDatan. Nii ei tarviisi sit kirjottaa johonki filuu.
 */
class Parser
{
public:
    Parser(QMap<QString,QString> config);
    /*!
     * \brief fullParse calls all other private methods
     * \param filename of the file to parse
     * \return TODO
     */
    bool fullParse();

private:
    /*!
     * \brief readFile saves filedata to unparsedDataTotal
     * \param filename ;)
     * \return TODO
     */
    bool readFile();
    /*!
     * \brief parseToTable parses the file down to just the table elements.
     * \return TODO
     */
    bool parseToTable();
    /*!
     * \brief parseTable does the final parsing, and writes the complete data to a txt file.
     * \return
     */
    bool parseTable();
  QString unparsedDataTotal_="";
  QString parsedData="";
  QMap <QString, QString> config_;

};

#endif // PARSER_H
