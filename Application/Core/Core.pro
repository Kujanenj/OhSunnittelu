TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt
QT += core

HEADERS += \
        Controller/parser.h \
        Controller/requester.h
SOURCES += \
        Controller/requester.cpp \
        main.cpp \
        Controller/parser.cpp

INCLUDEPATH += Controller/

DISTFILES += \
    Ui.qml
