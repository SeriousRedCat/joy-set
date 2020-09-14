BIN_DIR = ../../bin
OBJ_DIR = ../../obj
LIB_DIR = ../../lib
MOC = moc
UI = ui
RCC = rcc

MOC_DIR = $$MOC
UI_DIR = $$UI
RCC_DIR = $$RCC

CONFIG += c++1z

OBJECTS_DIR = $$OBJ_DIR/$$TARGET

win32{
    DEFINES += _USE_MATH_DEFINES
}

CONFIG(debug, debug|release){
    DEFINES += DEBUG_BUILD
    contains(CONFIG, staticlib){
        DESTDIR = $$LIB_DIR/$$TARGET
        TARGET = $$join(TARGET,,,d)
    }else{
        DESTDIR = $$BIN_DIR/debug
    }
}
CONFIG(release, debug|release){
    DEFINES += RELEASE_BUILD
    contains(CONFIG, staticlib){
        DESTDIR = $$LIB_DIR/$$TARGET
    }else{
        DESTDIR = $$BIN_DIR/release
    }
}
