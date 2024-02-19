#ifndef SERIALPORTDLG_H
#define SERIALPORTDLG_H

#include <QDialog>
#include <QDateTime>

#include "SerialPortAvailAble.h"
#include "GlobalSetting.h"

namespace Ui {
class SerialPortDlg;
}

class SerialPortDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SerialPortDlg(QWidget *parent = nullptr);
    ~SerialPortDlg();

    void init();


private:

    Ui::SerialPortDlg *ui;

    SerialPortAvailAble S_AvailAble;


};

#endif // SERIALPORTDLG_H
