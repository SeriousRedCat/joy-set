QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += c++17

TEMPLATE = app

TARGET = tests

DESTDIR = ../bin
OBJECTS_DIR = ../obj/$$TARGET

DEFINES += ALL_TESTS

QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS += --coverage

INCLUDEPATH += \
    ../include \
    ../src


LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

SOURCES +=  \
    ../3rdParty/catch2/main.cpp \
    common/gametest.cpp \
    common/growingmenuitemtest.cpp \
    common/leveltest.cpp

SOURCES += \
../src/common/fpscounter.cpp \
../src/common/game.cpp \
../src/common/growingmenuitem.cpp \
../src/common/growingmenuitemfactory.cpp \
../src/common/menubase.cpp \
../src/common/menubasefactory.cpp \
../src/common/menuitem.cpp \
../src/common/resourcemanager.cpp \
../src/common/stage.cpp
