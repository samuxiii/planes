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
    src/Notifier.cpp \
    src/Player.cpp \
    src/Score.cpp

HEADERS  += \
    include/Bullet.h \
    include/Enemies.h \
    include/Enemy.h \
    include/Game.h \
    include/Health.h \
    include/Notification.h \
    include/Notifier.h \
    include/Player.h \
    include/Score.h \
    include/Subscriber.h

INCLUDEPATH += include/

DISTFILES +=

RESOURCES += \
    resources.qrc

debug:DESTDIR = debug
debug:OBJECTS_DIR = debug/.obj
debug:MOC_DIR = debug/.moc
debug:RCC_DIR = debug/.rcc
debug:UI_DIR = debug/.ui

release:DESTDIR = release
release:OBJECTS_DIR = release/.obj
release:MOC_DIR = release/.moc
release:RCC_DIR = release/.rcc
release:UI_DIR = release/.ui


