#-------------------------------------------------
#
# Project created by QtCreator 2016-10-21T21:35:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cpp_game
TEMPLATE = app
QMAKE_MAC_SDK = macosx10.12

SOURCES += main.cpp \
    MyRect.cpp \
    Bullet.cpp \
    enemy.cpp \
    enemy2.cpp \
    game.cpp \
    health.cpp \
    score.cpp \
    resphlt.cpp \
    round.cpp \
    button.cpp \
    walls.cpp

HEADERS  += \
    myrect.h \
    Bullet.h \
    enemy.h \
    enemy2.h \
    game.h \
    health.h \
    score.h \
    resphlt.h \
    round.h \
    button.h \
    walls.h

RESOURCES += \
    img.qrc
