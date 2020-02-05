#include <iostream>
#include "parser.h"
#include <QMap>
using namespace std;

int main()
{

    QMap<QString,QString> example = {{"fileToRead", "../../Application/Data/data.txt"},
                                     {"fileToWrite", "../../Application/Data/dataOut"},
                                     {"tableStart", "</thead><tbody>"},
                                     {"tableEnd", "</table><div"},
                                     {"tableCellLeft", "7pt;\">"},
                                     {"tableCellRight","<"}};
Parser test = Parser(example,"false");

}

