QT       += core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_test
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app

SOURCES += main.cpp \
           GameBoard.cpp \
           ClickableLabel.cpp \
           Animal.cpp

