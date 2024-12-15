QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

win32:RC_ICONS += replacr.ico

SOURCES += \
    src/connection.cpp \
    src/createpresetwindow.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/presetmodel.cpp \
    src/presetswindow.cpp

HEADERS += \
    src/connection.h \
    src/createpresetwindow.h \
    src/mainwindow.h \
    src/presetmodel.h \
    src/presetswindow.h

FORMS += \
    src/createpresetwindow.ui \
    src/mainwindow.ui \
    src/presetswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
