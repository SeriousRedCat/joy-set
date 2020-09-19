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
    ../common/drawable.cpp \
    ../common/fpscounter.cpp \
    ../common/game.cpp \
    ../common/gameobject.cpp \
    ../common/growingmenuitem.cpp \
    ../common/growingmenuitemfactory.cpp \
    ../common/menubase.cpp \
    ../common/menubasefactory.cpp \
    ../common/menuitem.cpp \
    ../common/physicalobject.cpp \
    ../common/physicalstage.cpp \
    ../common/resourcemanager.cpp \
    ../common/stage.cpp \
    ball.cpp \
    ballcallback.cpp \
    basket.cpp \
    main.cpp \
    pointlistener.cpp \
    pointsinfotext.cpp \
    practice.cpp \
    realbasket.cpp

HEADERS += \
    ../../include/igame.hpp \
    ../../include/istage.hpp \
    ../../include/istagefactory.hpp \
    ../common/drawable.hpp \
    ../common/fpscounter.hpp \
    ../common/game.hpp \
    ../common/gameobject.hpp \
    ../common/growingmenuitem.hpp \
    ../common/growingmenuitemfactory.hpp \
    ../common/menubase.hpp \
    ../common/menubasefactory.hpp \
    ../common/menuitem.hpp \
    ../common/physicalobject.hpp \
    ../common/physicalstage.hpp \
    ../common/resourcemanager.hpp \
    ../common/stage.hpp \
    ball.hpp \
    ballcallback.hpp \
    basket.hpp \
    iball.hpp \
    ibasket.hpp \
    ipractice.h \
    pointlistener.hpp \
    pointsinfotext.hpp \
    practice.hpp \
    realbasket.hpp

INCLUDEPATH += \
    ../ \
    ../../include \
    ../../3rdParty

