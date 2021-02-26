#include <QObject>
#include <QDebug>
#include <QKeyEvent>
#include "snake.h"
#include "handleKeyboard.h"

GetKeyboard::GetKeyboard(QObject *parent) :
    QObject(parent) {

}

GetKeyboard::~GetKeyboard(void) {

}

void GetKeyboard::setup(QThread &cThread) {
    connect(&cThread, &QThread::finished, this, &QObject::deleteLater);
    connect(&cThread, SIGNAL(started()), this, SLOT(myTask()));
    this->keyThread = &cThread;
}

void GetKeyboard::handleKeyboard(int key_dir) {
    qDebug() << key_dir;
}

