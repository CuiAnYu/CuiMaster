#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThreadPool>

#include "Thread/TestThread.h"
#include "SerialPort/SerialPortDlg.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init();

    void connectSignalsAndSlots();

    void connectMenuActions();

    void showSerialPort();


private:

    Ui::MainWindow *ui;

    SerialPortDlg SerialDlg;

};
#endif
