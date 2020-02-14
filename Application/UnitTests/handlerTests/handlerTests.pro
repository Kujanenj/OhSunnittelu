QT += testlib
QT += core


TARGET += tst_parsertests
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++14
TEMPLATE = app
HEADERS +=  $$PWD/../../App/Controller/datahandler.h

SOURCES +=  tst_simpletests.cpp \
          $$PWD/../../App/Model/datahandler.cpp
INCLUDEPATH += ../../../Application/App/Model/
