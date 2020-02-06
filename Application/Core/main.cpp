#include <iostream>
#include <requester.h>


//Ei saatana pojat, ei tää maini voi olla tämmönen ;:D
int main()
{
    QMap<QString,QString> parameters;
    parameters.insert("dnn$ctr1025$Etusivu$ddlVuosi2x", "2019");
    parameters.insert("dnn$ctr1025$Etusivu$ddlMatka2x", "P50");
    parameters.insert("dnn$ctr1025$Etusivu$ddlIkaluokka2", "kaikki");
    parameters.insert("dnn$ctr1025$Etusivu$ddlKansalaisuus2x", "");
    parameters.insert("dnn$ctr1025$Etusivu$chkLstSukupuoli2", "kaikki");
    parameters.insert("dnn$ctr1025$Etusivu$txtHakuEtunimi2", "Veikko");
    parameters.insert("dnn$ctr1025$Etusivu$txtHakuSukunimi2", "");
    parameters.insert("dnn$ctr1025$Etusivu$txtHakuPaikkakunta2", "");
    parameters.insert("dnn$ctr1025$Etusivu$txtHakuJoukkue2", "");
    Requester req=Requester();
    req.DoRequest(parameters);



    QMap<QString,QString> example = {{"fileToRead", "../../Application/Data/data.txt"},
                                     {"fileToWrite", "../../Application/Data/dataOut"},
                                     {"tableStart", "</thead><tbody>"},
                                     {"tableEnd", "</table><div"},
                                     {"tableCellLeft", "7pt;\">"},
                                     {"tableCellRight","</td>"}};
    Parser test = Parser(example,"false");
    qDebug()<<test.fullParse();
    qDebug()<<"Super done";









}

