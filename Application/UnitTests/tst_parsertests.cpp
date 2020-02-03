#include <QtTest>
#include "parser.h"
// add necessary includes here


class parserTests : public QObject
{
    Q_OBJECT

public:
    parserTests();
    ~parserTests();

private slots:
    void test_fullParse();
    void test_failToRead();
    void test_failToFindTable();

private:
    QMap<QString,QString> example = {{"fileToRead", "../../Data/data.txt"},
                                     {"fileToWrite", "../../Data/dataOut"},
                                     {"tableStart", "</thead><tbody>"},
                                     {"tableEnd", "</table><div"},
                                     {"tableCellLeft", "7pt;\">"},
                                     {"tableCellRight","<"}};
    std::shared_ptr<Parser> testParser=nullptr;
    QMap<QString,QString> failexample=example;
};

parserTests::parserTests()
{

}

parserTests::~parserTests()
{

}

void parserTests::test_fullParse()
{

    testParser=std::make_shared<Parser>(example,"false");

    QVERIFY(testParser->fullParse().left(5)!="ERROR");
}
void parserTests::test_failToRead(){

    failexample["fileToRead"]="NOT A REAL FFASDSADASD";
    testParser=std::make_shared<Parser>(failexample,"false");

    QVERIFY(testParser->fullParse().left(5)=="ERROR");
}

void parserTests::test_failToFindTable(){
    failexample=example;
    failexample["tableStart"]="Does not exist";
    failexample["tableEnd"]="This does also not exist";
    testParser=std::make_shared<Parser>(failexample,"false");

    QVERIFY(testParser->fullParse().endsWith(")")==true);
}
QTEST_APPLESS_MAIN(parserTests)

#include "tst_parsertests.moc"
