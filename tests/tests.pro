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

SOURCES += $$PWD/../3rdParty/catch2/main.cpp \
    common/gametest.cpp \
    common/growingmenuitemtest.cpp \
    common/leveltest.cpp

SRC_PATH = ../src

SOURCES += \
    $$SRC_PATH/common/drawable.cpp \
    $$SRC_PATH/common/fpscounter.cpp \
    $$SRC_PATH/common/game.cpp \
    $$SRC_PATH/common/gameobject.cpp \
    $$SRC_PATH/common/growingmenuitem.cpp \
    $$SRC_PATH/common/growingmenuitemfactory.cpp \
    $$SRC_PATH/common/menubase.cpp \
    $$SRC_PATH/common/menubasefactory.cpp \
    $$SRC_PATH/common/menuitem.cpp \
    $$SRC_PATH/common/physicalobject.cpp \
    $$SRC_PATH/common/physicalstage.cpp \
    $$SRC_PATH/common/resourcemanager.cpp \
    $$SRC_PATH/common/stage.cpp \
    $$SRC_PATH/RealBasket/ball.cpp \
    $$SRC_PATH/RealBasket/ballcallback.cpp \
    $$SRC_PATH/RealBasket/basket.cpp \
    $$SRC_PATH/RealBasket/pointlistener.cpp \
    $$SRC_PATH/RealBasket/pointsinfotext.cpp \
    $$SRC_PATH/RealBasket/practice.cpp \
    $$SRC_PATH/RealBasket/realbasket.cpp

HEADERS += \
    $$SRC_PATH/../include/igame.hpp \
    $$SRC_PATH/../include/istage.hpp \
    $$SRC_PATH/../include/istagefactory.hpp \
    $$SRC_PATH/common/drawable.hpp \
    $$SRC_PATH/common/fpscounter.hpp \
    $$SRC_PATH/common/game.hpp \
    $$SRC_PATH/common/gameobject.hpp \
    $$SRC_PATH/common/growingmenuitem.hpp \
    $$SRC_PATH/common/growingmenuitemfactory.hpp \
    $$SRC_PATH/common/menubase.hpp \
    $$SRC_PATH/common/menubasefactory.hpp \
    $$SRC_PATH/common/menuitem.hpp \
    $$SRC_PATH/common/physicalobject.hpp \
    $$SRC_PATH/common/physicalstage.hpp \
    $$SRC_PATH/common/resourcemanager.hpp \
    $$SRC_PATH/common/stage.hpp \
    $$SRC_PATH/RealBasket/ball.hpp \
    $$SRC_PATH/RealBasket/ballcallback.hpp \
    $$SRC_PATH/RealBasket/basket.hpp \
    $$SRC_PATH/RealBasket/iball.hpp \
    $$SRC_PATH/RealBasket/ibasket.hpp \
    $$SRC_PATH/RealBasket/ipractice.h \
    $$SRC_PATH/RealBasket/pointlistener.hpp \
    $$SRC_PATH/RealBasket/pointsinfotext.hpp \
    $$SRC_PATH/RealBasket/practice.hpp \
    $$SRC_PATH/RealBasket/realbasket.hpp

INCLUDEPATH += \
    ../ \
    ../../include \
    ../../3rdParty
