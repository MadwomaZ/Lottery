TEMPLATE = app
CONFIG += console c++11
QMAKE_CXX = g++-4.9
QMAKE_CXXFLAGS += -std=c++14 -v
LIBS += -lcurl
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    circulation.cpp \
    lottery.cpp \
    html.cpp

HEADERS += \
    circulation.h \
    lottery.h \
    html.h
