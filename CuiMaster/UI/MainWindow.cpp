#include "UI/MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();    ///初始化软件控件

    // 线程池初始化，设置最大线程池数
    QThreadPool::globalInstance()->setMaxThreadCount(4);
    // 添加任务
    TestThread* task = new TestThread;
    QThreadPool::globalInstance()->start(task);


}

MainWindow::~MainWindow()
{
    delete ui;
}

///初始化软件
void MainWindow::init()
{
    //    RConfig.init(); ///读取配置文件
    //    _reslogger.setLogMessage("配置文件读取完毕。");
    //    _reslogger.checkAndCreateLogFile("ResLogger");  ///检测日志文件
    //    setWindowTitle("20通道电性能检测仪 V1.10 - 更新时间: " + QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));  ///软件标题
    //    Model.checkDB(); ///检测数据库文件
    connectSignalsAndSlots();   ///信号槽
}

///信号槽集合
void MainWindow::connectSignalsAndSlots()
{
    connectMenuActions();   ///菜单栏
    //    connectStatusButtonAndControls();   ///主界面控件
    //    connectResistanceServer();  ///通信信号槽
    //    connectParameterSettingDialog();    ///参数传递信号槽
    //    connect(this, &MainWindow::initializationResult, this, &MainWindow::handleInitializationResult);    ///初始化10通道设备
}

///菜单栏信号槽
void MainWindow::connectMenuActions()
{
    connect(ui->C_Serial, &QAction::triggered, this, &MainWindow::showSerialPort);    ///连接数据详情
//    connect(ui->help, &QAction::triggered, this, &MainWindow::showInstruction); ///使用手册
//    connect(ui->OperationLog, &QAction::triggered, this, &MainWindow::showOperationLog); ///操作日志
//    connect(ui->Exit, &QAction::triggered, this, &MainWindow::exit); ///退出
//    connect(ui->Settings, &QAction::triggered, this, &MainWindow::showSettings); ///参数设置
}

///串口通讯
void MainWindow::showSerialPort(){
    SerialDlg.show();
}
