#ifndef TETRIS_BATTLE_H
#define TETRIS_BATTLE_H

#include <map>
#include <vector>

#include "QObject"
#include "QDebug"

#include "common.h"

#define CW_MODE    1
#define CCW_MODE   2


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
    std::map<int, QString> tetrisTypeColor_decode= {
        {TETRIS_TYPE_NONE, "black"},
        {TETRIS_TYPE_I, "blue"},
        {TETRIS_TYPE_J, "blue"},
        {TETRIS_TYPE_L, "orange"},
        {TETRIS_TYPE_O, "yellow"},
        {TETRIS_TYPE_S, "green"},
        {TETRIS_TYPE_T, "purple"},
        {TETRIS_TYPE_Z, "red"},
    };
    tetris_pos_t current_pos;
    int current_tetris_type = TETRIS_TYPE_NONE;
    int hold_tetris_type = TETRIS_TYPE_NONE;
    rect_pos_t *each_rect;     // point to current_pos first rection
    int rectNumbers = 1;       // 0 is NULL object
    void gernerateNewTetris(void);
    void gernerateNewTetris(int tetris_type);
    int isDownExist(rect_pos_t *pos);
    void insertTetris2Map(void);
    void showMap(void);
    void handleKeyPut(void);
    void handleKeyCW_CCW(int cw_ccw_mode);
    void handleKeyHold(void);
    void checkLines(void);
Q_OBJECT
signals:
    void createRectSignal(QString componentName, int x, int y, QString color);

public slots:
    void startHandler(void);
    void stopHandler(void);
    void keyboardHandler(int dir);
    void updateHandler(void);
};


#endif /* TETRIS_BATTLE_H */
