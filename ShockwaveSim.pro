#-------------------------------------------------
#
# Project created by QtCreator 2012-03-04T23:24:55
#
#-------------------------------------------------
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = ShockwaveSim
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
        qcustomplot.cpp \
    shockwavecalculations.cpp \
    shockwaveparams.cpp \
    shockwavedataobj.cpp

HEADERS  += mainwindow.h \
         qcustomplot.h \
    shockwavecalculations.h \
    shockwaveparams.h \
    shockwavedataobj.h

FORMS    += mainwindow.ui \
    shockwaveparams.ui

