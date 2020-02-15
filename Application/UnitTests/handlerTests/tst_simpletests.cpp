#include <QtTest>
#include "datahandler.h"
// add necessary includes here

class simpleTests : public QObject
{
    Q_OBJECT

public:
    simpleTests();
    ~simpleTests();

private slots:
    void test_case1();
    void testSortingTime();
private:
    std::shared_ptr<Model::DataHandler> testHandler=nullptr;
};

simpleTests::simpleTests()
{
testHandler=std::make_shared<Model::DataHandler>();
}

simpleTests::~simpleTests()
{

}

void simpleTests::test_case1()
{

    QString empty="";
    testHandler->formMap(empty);

}


void simpleTests::testSortingTime(){

    QString empty="testing";
    testHandler->formMap(empty);
    QVERIFY(testHandler->getSortedDataVector().back().at(2)=="4:56:13.94");

}
QTEST_APPLESS_MAIN(simpleTests)

#include "tst_simpletests.moc"
