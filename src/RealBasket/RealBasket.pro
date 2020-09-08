TEMPLATE = app
CONFIG += c++17
CONFIG -= app_bundle

LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

RESOURCES += \
    resources.qrc

SOURCES += \
        ../common/game.cpp \
        ../common/menubase.cpp \
        ../common/menubasefactory.cpp \
        ../common/menuitem.cpp \
        ../common/resourcemanager.cpp \
        ../common/stage.cpp \
        main.cpp \
        realbasket.cpp

HEADERS += \
    ../../include/igame.hpp \
    ../../include/istage.hpp \
    ../../include/istagefactory.hpp \
    ../common/game.hpp \
    ../common/menubase.hpp \
    ../common/menubasefactory.hpp \
    ../common/menuitem.hpp \
    ../common/resourcemanager.hpp \
    ../common/stage.hpp \
    realbasket.hpp

INCLUDEPATH += \
    ../ \
    ../../include

