TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    fooditem.cpp \
    foodmanager.cpp \
    logger.cpp

HEADERS += \
    fooditem.h \
    foodmanager.h \
    logger.h
