#-------------------------------------------------
#
# Project created by QtCreator 2018-06-04T18:06:12
#
#-------------------------------------------------

QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT       += webenginewidgets
QT       += xml

TARGET = kSound
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    image.cpp \
    message.cpp \
    fichiermessages.cpp \
    objet.cpp \
    xmlobjetsreader.cpp \
    xmlcontactsreader.cpp \
    xmlmessagesreader.cpp \
    xmlhistoriquereader.cpp \
    xmlreader.cpp \
    listobjets.cpp \
    xmlobjetswriter.cpp \
    frameaddparam.cpp

HEADERS += \
        mainwindow.h \
    image.h \
    main.h \
    message.h \
    fichiermessages.h \
    objet.h \
    xmlobjetsreader.h \
    xmlcontactsreader.h \
    xmlmessagesreader.h \
    xmlhistoriquereader.h \
    xmlreader.h \
    listobjets.h \
    xmlobjetswriter.h \
    frameaddparam.h

FORMS += \
        mainwindow.ui
