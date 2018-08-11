#-------------------------------------------------
#
# Project created by QtCreator 2016-09-10T11:36:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AlignTable
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    columnalignedlayout.cpp \
    filteredtablewidget.cpp

HEADERS  += mainwindow.h \
    columnalignedlayout.h \
    filteredtablewidget.h

FORMS    += mainwindow.ui \
    filteredtablewidget.ui

CONFIG += c++11

DISTFILES += \
    README.md
