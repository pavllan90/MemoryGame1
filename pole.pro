#-------------------------------------------------
#
# Project created by QtCreator 2017-02-28T13:44:53
#
#-------------------------------------------------

QT       += core gui
QT       += opengl

TARGET = pole
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    card.cpp \
    glcard.cpp \
    window.cpp

HEADERS  += mainwindow.h \
    card.h \
    glcard.h \
    window.h

OTHER_FILES += \
    f1.png

FORMS += \
    window.ui
