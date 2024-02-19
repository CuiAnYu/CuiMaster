#include "SerialPortInit.h"

SerialPortInit::SerialPortInit()
{

}

///初始化串口
int SerialPortInit::init(QString portName)
{

    ///如果串口已经打开，直接返回0
    if (m_serialPort.isOpen()){return 0;}

    ///通信参数如下:[波特率：115200，数据位：8位，停止位：1位，校验位：无]
    m_portName.clear();
    m_portName=portName;

    m_serialPort.setPortName(portName);
    m_serialPort.setBaudRate(QSerialPort::Baud115200);
    m_serialPort.setDataBits(QSerialPort::Data8);
    m_serialPort.setStopBits(QSerialPort::OneStop);
    m_serialPort.setParity(QSerialPort::NoParity);

    bool ok=m_serialPort.open(QIODevice::ReadWrite);

    if(!ok){
        qDebug()<<"打开串口"<<portName<<"失败。错误码:"<<m_serialPort.error()<<"，信息:"<<m_serialPort.errorString();
        return m_serialPort.error();
    }

    return 0;
}
