QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++14

TEMPLATE = app

INCLUDEPATH += $$PROJECT_DIR

SOURCES +=  \
    gametest.cpp
