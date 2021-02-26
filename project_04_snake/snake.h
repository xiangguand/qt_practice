#ifndef SNAKE_H
#define SNAKE_H

#include "QObject"
#include "QDebug"
#include "QThread"
#include "common.h"
#include "handleKeyboard.h"

#define WINDOW_H    20
#define WINDOW_L    24


class Snake : public QObject {
public:
    GetKeyboard getKeyboard;
    QThread keyThread;
    Snake(QObject *obj);
    Snake(void);
    ~Snake(void);
    void setRootQObject(QObject *obj);
    void closeAll(void);
private:
    QObject *rootQObject;
    int dir;
    snake_pos_t pos;
    int getWindowPos(void);

Q_OBJECT
public slots:
    void startClick(void);
    void stopClick(void);
    void testClick(void);
    void updateHandler(void);
    void keyboardHandler(int dir);


};


#endif /* SNAKE_H */
