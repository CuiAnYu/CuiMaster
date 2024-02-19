#include "TestThread.h"

TestThread::TestThread() : QRunnable()
{
    ///任务执行完毕,该对象自动销毁
    setAutoDelete(true);
}

void TestThread::run()
{
  qDebug()<<"测试线程池启动";
}


TestThread::~TestThread()
{
}
