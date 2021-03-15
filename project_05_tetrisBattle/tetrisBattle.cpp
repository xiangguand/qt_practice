#include <string>
#include <cstdlib>
#include <ctime>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include "tetrisBattle.h"

using namespace std;

TetrisBattle::TetrisBattle(void) {
    qDebug() << "Constructor TetrisBattle";
}

TetrisBattle::~TetrisBattle(void) {
    qDebug() << "Deconstruct TetrisBattle";
}

void TetrisBattle::startHandler(void) {
    qDebug() << "start";
}

void TetrisBattle::stopHandler(void) {
    qDebug() << "stop";
}


