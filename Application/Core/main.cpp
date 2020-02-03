#include <iostream>
#include "parser.h"
#include <QMap>
using namespace std;

int main()
{

    QMap<QString,QString> example = {{"fileToRead", "../../Data/data.txt"},
                                     {"fileToWrite", "../../Data/dataOut"},
                                     {"tableStart", "</thead><tbody>"},
                                     {"tableEnd", "</table><div"},
                                     {"tableCellLeft", "7pt;\">"},
                                     {"tableCellRight","<"}};
Parser test = Parser(example);
test.fullParse();
}

void func ()
{

}
