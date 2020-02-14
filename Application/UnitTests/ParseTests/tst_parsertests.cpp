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
    QMap<QString,QString> example = {{"fileToRead", "testDataUnParsed.txt"},
                                     {"fileToWrite", "testDataParsed.txt"},
                                     {"tableStart", "</thead><tbody>"},
                                     {"tableEnd", "</table><div"},
                                     {"tableCellLeft", "7pt;\">"},
                                     {"tableCellRight","<"}};
    std::shared_ptr<Parser> testParser=nullptr;
    QMap<QString,QString> failexample=example;
    QString emptyData="";
};

parserTests::parserTests()
{

}

parserTests::~parserTests()
{

}

void parserTests::test_fullParse()
{

    testParser=std::make_shared<Parser>();
   testParser->fullParse(example,emptyData);


    QVERIFY(emptyData!="");

}
void parserTests::test_failToRead(){
    emptyData="";
    failexample["fileToRead"]="NOT A REAL FFASDSADASD";

    testParser->fullParse(failexample,emptyData);
    QVERIFY(emptyData=="");
}

void parserTests::test_failToFindTable(){
    failexample=example;
    failexample["tableStart"]="Does not exist";
    failexample["tableEnd"]="This does also not exist";

    testParser->fullParse(failexample,emptyData);
    QVERIFY(emptyData=="");
}
QTEST_APPLESS_MAIN(parserTests)

#include "tst_parsertests.moc"
