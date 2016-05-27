#-------------------------------------------------
#
# Project created by QtCreator 2012-03-04T23:24:55
#
#-------------------------------------------------
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = ShockwaveSim
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++0x -Wall
INCLUDEPATH = ./

SOURCES += main.cpp\
        mainwindow.cpp \
        qcustomplot.cpp \
    shockwavecalculations.cpp \
    shockwavedataobj.cpp \
    shockwaveparamsdlg.cpp \
    shockregion.cpp \

HEADERS  += mainwindow.h \
         qcustomplot.h \
    shockwavecalculations.h \
    shockwavedataobj.h \
    shockwaveparamsdlg.h \
    shockregion.h \

FORMS    += mainwindow.ui \
    shockwaveparamsdlg.ui

