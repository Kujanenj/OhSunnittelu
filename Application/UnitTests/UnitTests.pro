QT += testlib
QT += core


TARGET += tst_parsertests
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++14
TEMPLATE = app
HEADERS +=  $$PWD/../Core/parser.h

SOURCES +=  tst_parsertests.cpp \
          $$PWD/../Core/parser.cpp
INCLUDEPATH += ../../Core/
