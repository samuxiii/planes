#-------------------------------------------------
#
# Project created by QtCreator 2016-01-17T11:14:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Planes
TEMPLATE = app


SOURCES += main.cpp \
    ../../planes/Planes/Bullet.cpp \
    Enemy.cpp \
    Player.cpp \
    Score.cpp \
    Enemies.cpp

HEADERS  += \
    ../../planes/Planes/Bullet.h \
    Enemy.h \
    Player.h \
    Score.h \
    Enemies.h

DISTFILES +=
