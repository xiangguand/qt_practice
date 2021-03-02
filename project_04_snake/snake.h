#ifndef SNAKE_H
#define SNAKE_H

#include <QObject>
#include <QDebug>
#include "common.h"

#define DEFAULT_TIMER_INTERVAL  250
#define TIMER_INTERVAL_MIN      100
#define WINDOW_H                20   // X
#define WINDOW_L                24   // Y
#define WINDOW_MAX              WINDOW_H*WINDOW_L

// Macro to set the snake and food position
#define HEAD_POS_X  this->pos[0].x
#define HEAD_POS_Y  this->pos[0].y
#define FOOD_POS_X  this->food.x
#define FOOD_POS_Y  this->food.y

class Snake : public QObject {
public:
    Snake(QObject *obj);
    Snake(void);
    ~Snake(void);
    void setRootQObject(QObject *obj);
    void closeAll(void);
private:
    QObject *rootQObject;
    int dir = DIR_RIGHT;
    int num = 1;
    int score = 0;
    int timerInverval = DEFAULT_TIMER_INTERVAL;
    snake_pos_t pos[WINDOW_MAX];
    snake_pos_t food;
    int getWindowPos(int index);
    int getHeadPos(void);
    int getFoodPos(void);
    void generateFood(void);

Q_OBJECT
signals:
    void scoreSignalSend(int score);
    void timerIntervelSignal(int intvl);
    void gameoverSignalSend(void);

public slots:
    void startClick(void);
    void stopClick(void);
    void updateHandler(void);
    void keyboardHandler(int dir);


};


#endif /* SNAKE_H */
