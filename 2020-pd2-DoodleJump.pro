#-------------------------------------------------
#
# Project created by QtCreator 2020-04-22T13:25:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2020-pd2-DoodleJump
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

CONFIG += c++11

SOURCES += \
        background.cpp \
        bullet.cpp \
        doodle.cpp \
        main.cpp \
        mainwindow.cpp \
        monster.cpp \
        monster1.cpp \
        monster2.cpp \
        monster3.cpp \
        monster4.cpp \
        platform.cpp \
        platform__build.cpp \
        platform__recreate.cpp \
        platform_broken.cpp \
        platform_hor.cpp \
        platform_normal.cpp \
        platform_ver.cpp

HEADERS += \
        _basic.h \
        background.h \
        bullet.h \
        doodle.h \
        mainbullet.h \
        mainwindow.h \
        monster.h \
        monster1.h \
        monster2.h \
        monster3.h \
        monster4.h \
        platform.h \
        platform__build.h \
        platform__recreate.h \
        platform_broken.h \
        platform_hor.h \
        platform_normal.h \
        platform_ver.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES +=
