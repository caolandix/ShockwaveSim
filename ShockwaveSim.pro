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

INCLUDEPATH = ./SymbolicC++3-3.35/headers

SOURCES += main.cpp\
        mainwindow.cpp \
        qcustomplot.cpp \
    shockwavecalculations.cpp \
    shockwavedataobj.cpp \
    shockwaveparamsdlg.cpp \
    shockregion.cpp \
    SymbolicC++3-3.35/lisp/lambda/lambda.cpp

HEADERS  += mainwindow.h \
         qcustomplot.h \
    shockwavecalculations.h \
    shockwavedataobj.h \
    shockwaveparamsdlg.h \
    shockregion.h \
    SymbolicC++3-3.35/headers/symbolic/constants.h \
    SymbolicC++3-3.35/headers/symbolic/equation.h \
    SymbolicC++3-3.35/headers/symbolic/functions.h \
    SymbolicC++3-3.35/headers/symbolic/integrate.h \
    SymbolicC++3-3.35/headers/symbolic/number.h \
    SymbolicC++3-3.35/headers/symbolic/product.h \
    SymbolicC++3-3.35/headers/symbolic/solve.h \
    SymbolicC++3-3.35/headers/symbolic/sum.h \
    SymbolicC++3-3.35/headers/symbolic/symbol.h \
    SymbolicC++3-3.35/headers/symbolic/symbolic.h \
    SymbolicC++3-3.35/headers/symbolic/symbolicc++.h \
    SymbolicC++3-3.35/headers/symbolic/symerror.h \
    SymbolicC++3-3.35/headers/symbolic/symmatrix.h \
    SymbolicC++3-3.35/headers/array.h \
    SymbolicC++3-3.35/headers/cloning.h \
    SymbolicC++3-3.35/headers/derive.h \
    SymbolicC++3-3.35/headers/identity.h \
    SymbolicC++3-3.35/headers/matnorm.h \
    SymbolicC++3-3.35/headers/matrix.h \
    SymbolicC++3-3.35/headers/multinomial.h \
    SymbolicC++3-3.35/headers/polynomial.h \
    SymbolicC++3-3.35/headers/quatern.h \
    SymbolicC++3-3.35/headers/rational.h \
    SymbolicC++3-3.35/headers/symbolicc++.h \
    SymbolicC++3-3.35/headers/vecnorm.h \
    SymbolicC++3-3.35/headers/vector.h \
    SymbolicC++3-3.35/headers/verylong.h \
    SymbolicC++3-3.35/lisp/lambda/builtin_arith.h \
    SymbolicC++3-3.35/lisp/lambda/builtin_core.h \
    SymbolicC++3-3.35/lisp/lambda/builtin_io.h \
    SymbolicC++3-3.35/lisp/lambda/builtin_list.h \
    SymbolicC++3-3.35/lisp/lambda/builtin_math.h \
    SymbolicC++3-3.35/lisp/lambda/expression.h \
    SymbolicC++3-3.35/lisp/lisp.h

FORMS    += mainwindow.ui \
    shockwaveparamsdlg.ui

