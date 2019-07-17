#-------------------------------------------------
#
# Project created by QtCreator 2019-07-03T10:00:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = softwaer_design
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
        admin_denglu.cpp \
        admin_ui.cpp \
        ch_in_renut.cpp \
        ch_in_rest.cpp \
        ch_in_view.cpp \
        ch_view.cpp \
        chrenut.cpp \
        chrest.cpp \
        inrenut.cpp \
        inrest.cpp \
        inview.cpp \
        main.cpp \
        mainwindow.cpp \
        renut.cpp \
        renut_info.cpp \
        rest.cpp \
        sort.cpp \
        view.cpp \
        view_info.cpp \
        visitor.cpp

HEADERS += \
        admin_denglu.h \
        admin_ui.h \
        ch_in_renut.h \
        ch_in_rest.h \
        ch_in_view.h \
        ch_view.h \
        chrenut.h \
        chrest.h \
        datastructor.h \
        inrenut.h \
        inrest.h \
        inview.h \
        len_point.h \
        mainwindow.h \
        renut.h \
        renut_info.h \
        rest.h \
        sort.h \
        view.h \
        view_info.h \
        visitor.h

FORMS += \
        admin_denglu.ui \
        admin_ui.ui \
        ch_in_renut.ui \
        ch_in_rest.ui \
        ch_in_view.ui \
        ch_view.ui \
        chrenut.ui \
        chrest.ui \
        inrenut.ui \
        inrest.ui \
        inview.ui \
        mainwindow.ui \
        recommend.ui \
        renut.ui \
        renut_info.ui \
        rest.ui \
        view.ui \
        view_info.ui \
        visitor.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
