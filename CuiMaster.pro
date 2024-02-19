QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    GlobalSetting.cpp \
    SerialPort/SerialPortAvailAble.cpp \
    SerialPort/SerialPortDlg.cpp \
    SerialPort/SerialPortInit.cpp \
    Thread/MainThreadWork.cpp \
    Thread/TestThread.cpp \
    UI/MainWindow.cpp \
    main.cpp

HEADERS += \
    GlobalSetting.h \
    SerialPort/SerialPortAvailAble.h \
    SerialPort/SerialPortDlg.h \
    SerialPort/SerialPortInit.h \
    Thread/MainThreadWork.h \
    Thread/TestThread.h \
    UI/MainWindow.h

FORMS += \
    SerialPort/SerialPortDlg.ui \
    UI/MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
