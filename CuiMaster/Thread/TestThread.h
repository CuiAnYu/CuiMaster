#ifndef TESTTHREAD_H
#define TESTTHREAD_H

#include <QRunnable>
#include <QObject>
#include <QDebug>

class TestThread : public QObject, public QRunnable
{
    Q_OBJECT

public:
    explicit TestThread();
    ~TestThread();

    void run() override;
};


#endif


