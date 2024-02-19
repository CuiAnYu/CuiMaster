#ifndef SERIALPORTAVAILABLE_H
#define SERIALPORTAVAILABLE_H

#include <QComboBox>
#include <QSerialPortInfo>

class SerialPortAvailAble
{
public:

    SerialPortAvailAble();

    void AvailSerialPorts(QComboBox *comboBox);

};

#endif // SERIALPORTAVAILABLE_H
