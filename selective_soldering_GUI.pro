#-------------------------------------------------
#
# Project created by QtCreator 2016-03-11T12:30:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = selective_soldering_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    motorController.cpp \
    modbus/modbus-data.c \
    modbus/modbus-rtu.c \
    modbus/modbus-tcp.c \
    modbus/modbus.c

HEADERS  += mainwindow.h \
    modbus/config.h \
    modbus/modbus-private.h \
    modbus/modbus-rtu-private.h \
    modbus/modbus-rtu.h \
    modbus/modbus-tcp-private.h \
    modbus/modbus-tcp.h \
    modbus/modbus-version.h \
    modbus/modbus.h \
    motorController.h

FORMS    += mainwindow.ui
