#-------------------------------------------------
#
# Project created by QtCreator 2014-12-24T17:24:32
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = DS18B20_Qt
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    qcustomplot.cpp

HEADERS  += dialog.h \
    qcustomplot.h

FORMS    += dialog.ui

LIBS += -L/usr/local/lib -lwiringPi 

RESOURCES += \
    resources.qrc

   
