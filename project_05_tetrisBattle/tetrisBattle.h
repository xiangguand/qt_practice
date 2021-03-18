#ifndef TETRIS_BATTLE_H
#define TETRIS_BATTLE_H

#include "QObject"
#include "QDebug"

#include "common.h"

class TetrisBattle : public QObject {
public:
    TetrisBattle(QObject *root); 
    TetrisBattle(void);    
    ~TetrisBattle(void);    
private:
    QObject *root;
    int create_number;
    int x = 0;
    int y = 0;
    int dir = DIR_NONE;
Q_OBJECT
signals:
    void test_signal(QString componentName, int x, int y, QString color);

public slots:
    void startHandler(void);
    void stopHandler(void);
    void keyboardHandler(int dir);
    void updateHandler(void);
};


#endif /* TETRIS_BATTLE_H */
