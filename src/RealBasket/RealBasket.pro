TEMPLATE = app
CONFIG += c++17
CONFIG -= app_bundle

LIBS += -L../../lib/Box2D
LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

CONFIG(debug, debug|release): LIBS += -lBox2Dd
CONFIG(release, debug|release): LIBS += -lBox2D

RESOURCES += \
    resources.qrc

SOURCES += \
    ../common/fpscounter.cpp \
    ../common/game.cpp \
    ../common/growingmenuitem.cpp \
    ../common/growingmenuitemfactory.cpp \
    ../common/menubase.cpp \
    ../common/menubasefactory.cpp \
    ../common/menuitem.cpp \
    ../common/physicalstage.cpp \
    ../common/resourcemanager.cpp \
    ../common/stage.cpp \
    main.cpp \
    pointlistener.cpp \
    practice.cpp \
    realbasket.cpp

HEADERS += \
    ../../include/igame.hpp \
    ../../include/istage.hpp \
    ../../include/istagefactory.hpp \
    ../common/fpscounter.hpp \
    ../common/game.hpp \
    ../common/growingmenuitem.hpp \
    ../common/growingmenuitemfactory.hpp \
    ../common/menubase.hpp \
    ../common/menubasefactory.hpp \
    ../common/menuitem.hpp \
    ../common/physicalstage.hpp \
    ../common/resourcemanager.hpp \
    ../common/stage.hpp \
    iball.hpp \
    ipractice.h \
    pointlistener.hpp \
    practice.hpp \
    realbasket.hpp

INCLUDEPATH += \
    ../ \
    ../../include \
    ../../3rdParty

