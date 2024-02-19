#ifndef SERIALPORTINIT_H
#define SERIALPORTINIT_H

#include <QString>
#include <QSerialPort>
#include <QDebug>

class SerialPortInit
{
public:

    SerialPortInit();

    int init(QString portName);

private:

    QSerialPort m_serialPort;

    QString m_portName;

};

#endif // SERIALPORTINIT_H
