#include <string>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include "snake.h"
#include "handleKeyboard.h"

using namespace std;

Snake::Snake(void) {
    qDebug() << "Constructor snake";
}

Snake::Snake(QObject *obj) {
    if(obj == NULL) {
        qDebug() << "RootQObject is NULL";
    }
    else {
        this->rootQObject = obj;
        qDebug() << "Constructor snake";
    }
}

Snake::~Snake(void) {
    qDebug() << "Deconstruct snake";
    this->keyThread.quit();
}

void Snake::setRootQObject(QObject *obj) {
    this->rootQObject = obj;
}

void Snake::startClick(void) {
    qDebug() << "Start click";
    // create the snake head
    this->pos.x = (WINDOW_H>>1);
    this->pos.y = (WINDOW_L>>1);
    qDebug() << getWindowPos();
    this->rootQObject->findChild<QObject *>(QStringLiteral("skB%1").arg(getWindowPos()))->setProperty("visible", true);
    this->rootQObject->findChild<QObject *>(QStringLiteral("skB%1").arg(getWindowPos()))->setProperty("color", "red");

}

void Snake::stopClick(void) {
    qDebug() << "Stop click";

}

void Snake::testClick(void) {
    qDebug() << "Test click";

}

void Snake::keyboardHandler(int dir) {
    qDebug() << "Handle keyboard: " << dir;
    this->dir = dir;
}

void Snake::updateHandler(void) {
    this->rootQObject->findChild<QObject *>(QStringLiteral("skB%1").arg(getWindowPos()))->setProperty("visible", false);

    if(this->dir == DIR_UP) {
        this->pos.x--;
    }
    else if(this->dir == DIR_DOWN) {
        this->pos.x++;
    }
    else if(this->dir == DIR_LEFT) {
        this->pos.y--;
    }
    else if(this->dir == DIR_RIGHT) {
        this->pos.y++;
    }
    this->rootQObject->findChild<QObject *>(QStringLiteral("skB%1").arg(getWindowPos()))->setProperty("visible", true);
}

int Snake::getWindowPos(void) {
    return this->pos.x + WINDOW_H*this->pos.y;
}

void Snake::closeAll(void) {
    for(int i=0;i<20*24;i++) {
        this->rootQObject->findChild<QObject *>(QStringLiteral("skB%1").arg(i))->setProperty("visible", false);
    }
}