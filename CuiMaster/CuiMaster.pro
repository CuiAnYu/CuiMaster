QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    Thread/MainThreadWork.cpp \
    Thread/TestThread.cpp \
    UI/MainWindow.cpp \
    main.cpp

HEADERS += \
    Thread/MainThreadWork.h \
    Thread/TestThread.h \
    UI/MainWindow.h

FORMS += \
    UI/MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
