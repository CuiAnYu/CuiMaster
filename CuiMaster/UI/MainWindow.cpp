#include "UI/MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


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

