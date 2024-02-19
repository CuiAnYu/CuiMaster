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
    setControlsEnabled(false);
    connectCheckBox();  ///选择框信号槽
}

///初始化可用串口
void SerialPortDlg::on_cominitButton_clicked()
{
    int com1 = S_Init.init(ui->comboBox_1->currentText());
    int com2 = S_Init.init(ui->comboBox_2->currentText());
    //  qDebug()<<"测试初始化串口的返回值:"<<com1<<com2;
}

///初始化不可用控件
void SerialPortDlg::setControlsEnabled(bool enabled)
{
    ui->frame_text->setEnabled(enabled);
    ui->order_text->setEnabled(enabled);
    ui->CRC_text->setEnabled(enabled);
    ui->end_text->setEnabled(enabled);
}

///选择框信号槽
void SerialPortDlg::connectCheckBox()
{
    connect(ui->frame, &QCheckBox::stateChanged, this, &SerialPortDlg::onFrameStateChanged);
    connect(ui->order, &QCheckBox::stateChanged, this, &SerialPortDlg::onOrderStateChanged);
    connect(ui->CRC, &QCheckBox::stateChanged, this, &SerialPortDlg::onCRCStateChanged);
    connect(ui->end, &QCheckBox::stateChanged, this, &SerialPortDlg::onEndStateChanged);

}

///选择框状态改变[帧头]
void SerialPortDlg::onFrameStateChanged(int state)
{
    bool isChecked = (state == Qt::Checked);
    ui->frame_text->setEnabled(isChecked);
}

///选择框状态改变[指令码]
void SerialPortDlg::onOrderStateChanged(int state)
{
    bool isChecked = (state == Qt::Checked);
    ui->order_text->setEnabled(isChecked);
}

///选择框状态改变[CRC]
void SerialPortDlg::onCRCStateChanged(int state)
{
    bool isChecked = (state == Qt::Checked);
    ui->CRC_text->setEnabled(isChecked);
}

///选择框状态改变[帧尾]
void SerialPortDlg::onEndStateChanged(int state)
{
    bool isChecked = (state == Qt::Checked);
    ui->end_text->setEnabled(isChecked);
}
