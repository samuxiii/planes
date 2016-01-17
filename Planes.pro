#-------------------------------------------------
#
# Project created by QtCreator 2016-01-17T11:14:32
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Planes
TEMPLATE = app


SOURCES += main.cpp \
    ../../planes/Planes/Bullet.cpp \
    Enemy.cpp \
    Player.cpp \
    Score.cpp \
    Enemies.cpp \
    Game.cpp \
    ../../planes/Planes/Health.cpp

HEADERS  += \
    ../../planes/Planes/Bullet.h \
    Enemy.h \
    Player.h \
    Score.h \
    Enemies.h \
    Game.h \
    ../../planes/Planes/Health.h

DISTFILES +=

RESOURCES += \
    Resources.qrc
