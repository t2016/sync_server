QT -= gui
QT += core network

CONFIG += c++11

TARGET = sync_server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    cxxserver.cpp \
    cxxfile.cpp \
    repository.cpp \
    tree.cpp

HEADERS += \
    cxxserver.h \
    cxxfile.h \
    repository.h \
    tree.h


