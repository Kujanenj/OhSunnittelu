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

private:
    QMap<QString,QString> example = {{"fileToRead", "../../Data/data.txt"},
                                     {"fileToWrite", "../../Data/dataOut"},
                                     {"tableStart", "</thead><tbody>"},
                                     {"tableEnd", "</table><div"},
                                     {"tableCellLeft", "7pt;\">"},
                                     {"tableCellRight","<"}};
    std::shared_ptr<Parser> testParser=nullptr;
};

parserTests::parserTests()
{

}

parserTests::~parserTests()
{

}

void parserTests::test_fullParse()
{

    testParser=std::make_shared<Parser>(example);

    QVERIFY(testParser->fullParse()=="parse complete");
}
void parserTests::test_failToRead(){

    example["fileToRead"]="NOT A REAL FFASDSADASD";
    testParser=std::make_shared<Parser>(example);

    QVERIFY(testParser->fullParse()=="file to read not found");
}
QTEST_APPLESS_MAIN(parserTests)

#include "tst_parsertests.moc"
