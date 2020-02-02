#ifndef PARSER_H
#define PARSER_H
#include <QFile>
#include <QDebug>

/*!
 * \brief The Parser class parses the finlandiahiihtoSivu. Writes parsed table data a txt file.
 * TODO: kommenttia. Kaikki turvacheckit puuttuu ihan kokonaan. Jos kusee jotenki niin ei saada ikinä tietää.
 * Vois kans lisätä jonku getin joka palauttaa ton parsedDatan. Nii ei tarviisi sit kirjottaa johonki filuu.
 */
class Parser
{
public:
    Parser();
    /*!
     * \brief fullParse calls all other private methods
     * \param filename of the file to parse
     * \return TODO
     */
    bool fullParse(QString filename);

private:
    /*!
     * \brief readFile saves filedata to unparsedDataTotal
     * \param filename ;)
     * \return TODO
     */
    bool readFile(QString filename);
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

};

#endif // PARSER_H
