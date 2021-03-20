#ifndef TETRIS_BATTLE_H
#define TETRIS_BATTLE_H

#include <map>

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
    // Define the tetris battle map stack
    int tetrisMap[TETRIS_HEIGHT][TETRIS_WIDTH];
    int dir = DIR_NONE;
    std::map<int, QString> tetris_decode = {
        {TETRIS_TYPE_NONE, "None"},
        {TETRIS_TYPE_I, "I shape"},
        {TETRIS_TYPE_J, "J shape"},
        {TETRIS_TYPE_L, "L shape"},
        {TETRIS_TYPE_O, "O shape"},
        {TETRIS_TYPE_S, "S shape"},
        {TETRIS_TYPE_T, "T shape"},
        {TETRIS_TYPE_Z, "Z shape"},
    };
    std::map<int, tetris_pos_t> tetrisTypeDefaultPos_decode= {
        {TETRIS_TYPE_NONE, I_DEFAULT_POS},
        {TETRIS_TYPE_I, I_DEFAULT_POS},
        {TETRIS_TYPE_J, J_DEFAULT_POS},
        {TETRIS_TYPE_L, L_DEFAULT_POS},
        {TETRIS_TYPE_O, O_DEFAULT_POS},
        {TETRIS_TYPE_S, S_DEFAULT_POS},
        {TETRIS_TYPE_T, T_DEFAULT_POS},
        {TETRIS_TYPE_Z, Z_DEFAULT_POS},
    };
    tetris_pos_t current_pos;
    rect_pos_t *each_rect;     // point to current_pos first rection
    int rectNumbers = 0;
    void gernerateNewTetris(void);
    int isDownExist(rect_pos_t *pos);
    void insertTetris2Map(void);
    void showMap(void);
Q_OBJECT
signals:
    void createRectsignal(QString componentName, int x, int y, QString color);

public slots:
    void startHandler(void);
    void stopHandler(void);
    void keyboardHandler(int dir);
    void updateHandler(void);
};


#endif /* TETRIS_BATTLE_H */
