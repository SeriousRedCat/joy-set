QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++17

TEMPLATE = app

DEFINES += ALL_TESTS

INCLUDEPATH = ../include

LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

SOURCES +=  \
    ../3rdParty/catch2/main.cpp \
    common/gametest.cpp \
    common/leveltest.cpp

SOURCES += \
    ../src/common/game.cpp
