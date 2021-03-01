#include <string>
#include <cstdlib>
#include <ctime>
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
    HEAD_POS_X = (WINDOW_H>>1);
    HEAD_POS_Y = (WINDOW_L>>1);

    this->num = 1;
    for(int i=0;i<WINDOW_MAX;i++) {
        this->rootQObject->findChild<QObject *>(QStringLiteral("skB%1").arg(i))->setProperty("visible", false);
        this->rootQObject->findChild<QObject *>(QStringLiteral("skB%1").arg(i))->setProperty("color", "black");
    }

    this->rootQObject->findChild<QObject *>(QStringLiteral("skB%1").arg(getHeadPos()))->setProperty("visible", true);
    this->rootQObject->findChild<QObject *>(QStringLiteral("skB%1").arg(getHeadPos()))->setProperty("color", "red");
    timerIntervelSignal(DEFAULT_TIMER_INTERVAL);

    // Initialize the random time seed
    srand(time(NULL));

    generateFood();
}

void Snake::stopClick(void) {
    qDebug() << "Stop click";
    gameoverSignalSend();
}

void Snake::testClick(void) {
    qDebug() << "Test click";
}

void Snake::keyboardHandler(int dir) {
    qDebug() << "Handle keyboard: " << dir;
    this->dir = dir;
}

void Snake::updateHandler(void) {
    this->rootQObject->findChild<QObject *>(QStringLiteral("skB%1").arg(getHeadPos()))->setProperty("visible", false);
    this->rootQObject->findChild<QObject *>(QStringLiteral("skB%1").arg(getWindowPos(this->num-1)))->setProperty("visible", false);

    if((HEAD_POS_X == FOOD_POS_X) && (HEAD_POS_Y == FOOD_POS_Y)) {
        qDebug() << "Eat";
        scoreSignalSend(++this->score);
        this->pos[num].x = this->pos[num-1].x;
        this->pos[num].y = this->pos[num-1].y;
        generateFood();
        this->num++;
        timerInverval -= 5;
        if(timerInverval < TIMER_INTERVAL_MIN) {
            timerInverval = TIMER_INTERVAL_MIN;
        }
        timerIntervelSignal(timerInverval);
    }

    
    // Copy old snake body
    snake_pos_t *copyBody = new snake_pos_t[this->num];
    memcpy(copyBody, this->pos, this->num*sizeof(snake_pos_t));
    
    if(this->dir == DIR_UP) {
        HEAD_POS_X--;
    }
    else if(this->dir == DIR_DOWN) {
        HEAD_POS_X++;
    }
    else if(this->dir == DIR_LEFT) {
        HEAD_POS_Y--;
    }
    else if(this->dir == DIR_RIGHT) {
        HEAD_POS_Y++;
    }

    // check in out of the window
    if((HEAD_POS_X >= WINDOW_H) || (HEAD_POS_Y >= WINDOW_L) || 
        (HEAD_POS_X < 0) || (HEAD_POS_Y < 0)) {
        gameoverSignalSend();
        return ;
    }

    // Update the snake body
    for(int i=1;i<this->num;i++) {
        this->pos[i].x = copyBody[i-1].x;
        this->pos[i].y = copyBody[i-1].y;
    }

    // Head
    this->rootQObject->findChild<QObject *>(QStringLiteral("skB%1").arg(getHeadPos()))->setProperty("visible", true);
    this->rootQObject->findChild<QObject *>(QStringLiteral("skB%1").arg(getHeadPos()))->setProperty("color", "red");
    qDebug() << "HEAD: " << this->pos[0].x << ", " << this->pos[0].y;

    // Body
    for(int i=1;i<this->num;i++) {
        qDebug() << "BODY: " << this->pos[i].x << ", " << this->pos[i].y;
        this->rootQObject->findChild<QObject *>(QStringLiteral("skB%1").arg(getWindowPos(i)))->setProperty("visible", true);
        this->rootQObject->findChild<QObject *>(QStringLiteral("skB%1").arg(getWindowPos(i)))->setProperty("color", "black");
        
        // Head eat body check
        if((HEAD_POS_X == this->pos[i].x) && (HEAD_POS_Y == this->pos[i].y)) {
            gameoverSignalSend();
            return ;
        }
    }

    
    delete copyBody;
}

int Snake::getWindowPos(int index) {
    return this->pos[index].x + WINDOW_H*this->pos[index].y;
}

int Snake::getHeadPos(void) {
    return HEAD_POS_X + WINDOW_H*HEAD_POS_Y;
}

int Snake::getFoodPos(void) {
    return FOOD_POS_X + WINDOW_H*FOOD_POS_Y;
}

void Snake::generateFood(void) {
    FOOD_POS_X = rand() % WINDOW_H;
    FOOD_POS_Y = rand() % WINDOW_L;
    for(int i=1;i<this->num;i++) {
        if((FOOD_POS_X == this->pos[i].x) && (FOOD_POS_Y == this->pos[i].y)) {
            generateFood();
        }
    }
    this->rootQObject->findChild<QObject *>(QStringLiteral("skB%1").arg(getFoodPos()))->setProperty("visible", true);
    this->rootQObject->findChild<QObject *>(QStringLiteral("skB%1").arg(getFoodPos()))->setProperty("color", "yellow");
}

void Snake::closeAll(void) {
    for(int i=0;i<20*24;i++) {
        this->rootQObject->findChild<QObject *>(QStringLiteral("skB%1").arg(i))->setProperty("visible", false);
    }
}
