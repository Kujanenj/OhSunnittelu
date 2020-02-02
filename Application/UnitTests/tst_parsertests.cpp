#include <QtTest>

// add necessary includes here

class parserTests : public QObject
{
    Q_OBJECT

public:
    parserTests();
    ~parserTests();

private slots:
    void test_case1();

};

parserTests::parserTests()
{

}

parserTests::~parserTests()
{

}

void parserTests::test_case1()
{

}

QTEST_APPLESS_MAIN(parserTests)

#include "tst_parsertests.moc"
