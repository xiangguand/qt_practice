#include <string>
#include "QDebug"
#include "snake.h"

using namespace std;

snake::snake(void) {
    qDebug() << "Constructor snake";
}

snake::snake(QObject *obj) {
    if(obj == NULL) {
        qDebug() << "RootQObject is NULL";
    }
    else {
        this->rootQObject = obj;
        qDebug() << "Constructor snake";
    }
}

snake::~snake(void) {
    qDebug() << "Deconstruct snake";
}

void snake::setRootQObject(QObject *obj) {
    this->rootQObject = obj;
}

void snake::startClick(void) {
    qDebug() << "Start click";
    
}

void snake::stopClick(void) {
    qDebug() << "Stop click";
}

void snake::testClick(void) {
    qDebug() << "Test click";
    static char ww = true;
    if(ww) ww = false;
    else ww = true;
    for(int i=0;i<20*24;i++) {
        QObject *obj = this->rootQObject->findChild<QObject *>(QStringLiteral("skB%1").arg(i));
        obj->setProperty("visible", ww);
    }

}

