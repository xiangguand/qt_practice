#include <string>
#include <cstdlib>
#include <ctime>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include "tetrisBattle.h"

using namespace std;

TetrisBattle::TetrisBattle(QObject *root) {
    qDebug() << "Constructor TetrisBattle";
    this->root = root;
}

TetrisBattle::TetrisBattle(void) {
    qDebug() << "Constructor TetrisBattle";
}

TetrisBattle::~TetrisBattle(void) {
    qDebug() << "Deconstruct TetrisBattle";
}

void TetrisBattle::startHandler(void) {
    qDebug() << "start";
    TetrisBattle::test_signal("123", this->x, this->y, "green");

}

void TetrisBattle::stopHandler(void) {
    qDebug() << "stop";
}

void TetrisBattle::keyboardHandler(int dir) {
    this->dir = dir;
    if(this->dir == DIR_UP) {
        
    }
    else if(this->dir == DIR_DOWN) {
        this->y += 50;
    }
    else if(this->dir == DIR_LEFT) {
        this->x -= 50;
    }
    else if(this->dir == DIR_RIGHT) {
        this->x += 50;
    }

    if(this->y >= 50*20) {
        this->y = 0;
    }
    if(this->x < 0) x = 0;
    else if(this->x >= 50*9) x = 50*9;

    QObject *a = this->root->findChild<QObject *>("123");
    if(a != NULL) {
        a->setProperty("x", this->x);
        a->setProperty("y", this->y);
    }
}

void TetrisBattle::updateHandler(void) {
    QObject *a = this->root->findChild<QObject *>("123");
    if(a != NULL) {
        this->y += 50;

        if(this->y >= 50*20) {
            this->y = 0;
        }

        a->setProperty("x", this->x);
        a->setProperty("y", this->y);
    }
}


