#-------------------------------------------------
#
# Project created by QtCreator 2016-03-11T12:30:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = selective_soldering_GUI
TEMPLATE = app

ICON = selective_soldering_GUI.icns

SOURCES += main.cpp\
        mainwindow.cpp \
    csvparser/csvparser.c \
    fileParser.c \
    motorController.cpp \
    inspectionCamera.cpp \
    mat2qimage.cpp\


HEADERS  += mainwindow.h \
    csvparser/csvparser.h \
    fileParser.h \
    motorController.h \
    inspectionCamera.h \
    mat2qimage.h \

INCLUDEPATH += /usr/local/include/modbus
LIBS += -L/usr/local/lib -lmodbus

QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.10

CONFIG += c++11
INCLUDEPATH += /usr/local/include/

LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_flann
LIBS += -lopencv_imgcodecs
LIBS += -lopencv_videoio

FORMS    += mainwindow.ui
