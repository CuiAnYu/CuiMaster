#include "SerialPortAvailAble.h"

SerialPortAvailAble::SerialPortAvailAble()
{

}

/// 显示可用串口，更新到 combobox[接收UI类型参数(控件的名称)]
void SerialPortAvailAble::AvailSerialPorts(QComboBox *comboBox)
{
    comboBox->clear();

    QList<QSerialPortInfo> serialPortList = QSerialPortInfo::availablePorts();

    for (const QSerialPortInfo &portInfo : serialPortList)
    {
        comboBox->addItem(portInfo.portName());
    }
}
