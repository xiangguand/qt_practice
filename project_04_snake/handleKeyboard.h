#ifndef GET_KEYBOARD_H
#define GET_KEYBOARD_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QKeyEvent>
#include "common.h"

class GetKeyboard : public QObject {
Q_OBJECT

public:
    explicit GetKeyboard(QObject *parent = 0); 
    ~GetKeyboard(void); 
    
    QThread *keyThread;
    void setup(QThread &cThread);
    void StopTask(void);

public slots:
    void handleKeyboard(int key_dir);


};

#endif /* GET_KEYBOARD_H */
