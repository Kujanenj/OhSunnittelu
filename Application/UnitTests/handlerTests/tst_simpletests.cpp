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
private:
    std::shared_ptr<DataHandler> testHandler=nullptr;
};

simpleTests::simpleTests()
{

}

simpleTests::~simpleTests()
{

}

void simpleTests::test_case1()
{
    testHandler=std::make_shared<DataHandler>();
    QString empty="";
    testHandler->formMap(empty);

}

QTEST_APPLESS_MAIN(simpleTests)

#include "tst_simpletests.moc"
