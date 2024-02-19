#ifndef SERIALPORTDLG_H
#define SERIALPORTDLG_H

#include <QDialog>
#include <QDateTime>

#include "SerialPortAvailAble.h"
#include "SerialPortInit.h"
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

    void setControlsEnabled(bool enabled);

    void connectCheckBox();

    void onFrameStateChanged(int state);

    void onOrderStateChanged(int state);

    void onCRCStateChanged(int state);

    void onEndStateChanged(int state);



private slots:

    void on_cominitButton_clicked();

private:

    Ui::SerialPortDlg *ui;

    SerialPortAvailAble S_AvailAble;

    SerialPortInit S_Init;


};

#endif // SERIALPORTDLG_H
