TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    udpserver.cpp \
    timeduration.cpp

HEADERS += \
    udpserver.h \
    timeduration.h
