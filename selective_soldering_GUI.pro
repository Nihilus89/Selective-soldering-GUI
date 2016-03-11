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
    modbus/modbus.c \
    inspectionCamera.cpp \
    csvparser/csvparser.c \
    fileParser.c

HEADERS  += mainwindow.h \
    modbus/config.h \
    modbus/modbus-private.h \
    modbus/modbus-rtu-private.h \
    modbus/modbus-rtu.h \
    modbus/modbus-tcp-private.h \
    modbus/modbus-tcp.h \
    modbus/modbus-version.h \
    modbus/modbus.h \
    motorController.h \
    csvparser/csvparser.h \
    fileParser.h \
    inspectionCamera.h

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_features2d -lopencv_imgcodecs -lopencv_highgui -lopencv_videoio -lopencv_imgproc
`LIBS += pkg-config --libs opencv`

FORMS    += mainwindow.ui
