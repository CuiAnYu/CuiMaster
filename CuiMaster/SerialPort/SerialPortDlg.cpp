#include "SerialPortDlg.h"
#include "ui_SerialPortDlg.h"

SerialPortDlg::SerialPortDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialPortDlg)
{
    ui->setupUi(this);
    GlobalSetting::init();
    init();
}

SerialPortDlg::~SerialPortDlg()
{
    delete ui;
}

///初始化
void SerialPortDlg::init()
{
    setWindowTitle("串口通信部分 " + GlobalSetting::softwareVersion + " - 更新时间: " + QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));  ///软件标题
    S_AvailAble.AvailSerialPorts(ui->comboBox_1);    ///显示可用串口
    S_AvailAble.AvailSerialPorts(ui->comboBox_2);


}
