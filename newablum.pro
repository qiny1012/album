#-------------------------------------------------
#
# Project created by QtCreator 2018-04-29T16:16:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = newablum
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    datemodel.cpp \
    helpui.cpp

HEADERS  += mainwindow.h \
    datemodel.h \
    helpui.h

FORMS    += mainwindow.ui \
    helpui.ui

RESOURCES += \
    res.qrc
