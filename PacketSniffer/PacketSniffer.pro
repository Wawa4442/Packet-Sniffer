QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
INCLUDEPATH += "$$PWD\Include"
LIBS += "-L$$PWD\Lib\x64" -lwpcap -lPacket -lws2_32
DEFINES += WPCAP

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    errordialog.cpp \
    filtersdialog.cpp \
    help.cpp \
    main.cpp \
    mainwindow.cpp \
    packetsniffer.cpp

HEADERS += \
    errordialog.h \
    filtersdialog.h \
    help.h \
    mainwindow.h \
    packetsniffer.h

FORMS += \
    errordialog.ui \
    filtersdialog.ui \
    help.ui \
    mainwindow.ui \
    packetsniffer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
