#-------------------------------------------------
#
# Project created by QtCreator 2016-01-17T11:14:32
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = planes
TEMPLATE = app

CONFIG += c++11
CONFIG += release

SOURCES += src/main.cpp \
    src/Bullet.cpp \
    src/Enemies.cpp \
    src/Enemy.cpp \
    src/Game.cpp \
    src/Health.cpp \
    src/Player.cpp \
    src/Score.cpp

INCLUDEPATH += include/

HEADERS  += \
    include/Bullet.h \
    include/Enemies.h \
    include/Enemy.h \
    include/Game.h \
    include/Health.h \
    include/Player.h \
    include/Score.h

DISTFILES +=

RESOURCES += \
    resources.qrc
