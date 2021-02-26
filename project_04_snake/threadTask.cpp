// #include <QObject>
// #include <QDebug>
// #include <QKeyEvent>
// #include "snake.h"
// #include "threadTask.h"

// ThreadTask::ThreadTask(QObject *parent) :
//     QObject(parent) {

// }

// ThreadTask::~ThreadTask(void) {

// }

// void ThreadTask::setup(QThread &cThread) {
//     // connect(&cThread, &QThread::finished, this, &QObject::deleteLater);
//     // connect(&cThread, SIGNAL(started()), this, SLOT(myTask()));
//     this->keyThread = &cThread;
// }

// void ThreadTask::myTask(void) {
//     qDebug() << "Thread run";

// }

