#-------------------------------------------------
#
# Project created by QtCreator 2023-08-29T17:43:20
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mplayer_Linux
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    longinform.cpp

HEADERS  += mainwindow.h \
    longinform.h

FORMS    += mainwindow.ui \
    longinform.ui

RESOURCES += \
    player.qrc
