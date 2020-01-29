QT       += core network webenginewidgets

QT       -= gui

TARGET = QHttpDownload
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    downloader.cpp

HEADERS += \
    downloader.h

DISTFILES += \
    Qml.qml
