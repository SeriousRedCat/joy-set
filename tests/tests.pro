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
    ../3rdParty \
    ../include \
    ../src

LIBS += -L../lib/Box2D
LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

CONFIG(debug, debug|release): LIBS += -lBox2Dd
CONFIG(release, debug|release): LIBS += -lBox2D

HEADERS += $$files($$PWD/../src/*.hpp, true)
HEADERS += $$files($$PWD/../include/*.hpp)
HEADERS += $$PWD/../3rdParty/catch2/catch.hpp

SOURCES += $$files($$PWD/../src/*.cpp, true)
SOURCES += $$files($$PWD/*.cpp, true)
SOURCES -= $$files($$PWD/moc_*.cpp, true)
SOURCES -= $$files($$PWD/../src/main.*, true)
SOURCES += $$PWD/../3rdParty/catch2/main.cpp
