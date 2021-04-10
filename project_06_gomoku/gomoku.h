#ifndef GOMOKU_H
#define GOMOKU_H

#include <map>
#include <vector>

#include "QObject"
#include "QDebug"

#include "common.h"

#define USER_NUM     2
#define NONE_USER    0
#define BLACK_USER   1
#define WHITE_USER   2

#define GOMOKU_MAP_NONE  0
#define GOMOKU_MAP_BLACK 1
#define GOMOKU_MAP_WHITE 2


class Gomoku : public QObject {
public:
    Gomoku(QObject *root); 
    Gomoku(void);
    ~Gomoku(void);    
private:
    void init(void);
    std::vector<QString> collectPiece;
    int gomokuMap[GOMOKU_WIDTH][GOMOKU_HEIGHT];
    std::map<int, QString> gomoku_color = {
        {GOMOKU_MAP_NONE, "red"},
        {GOMOKU_MAP_BLACK, GOMOKU_BLACK_COLOR},
        {GOMOKU_MAP_WHITE, GOMOKU_WHITE_COLOR},
    };
    void clearMap(void);
    void showMap(void);
    int pieceCnt = 0;
    const QString userColor[USER_NUM] = {GOMOKU_BLACK_COLOR, GOMOKU_WHITE_COLOR};
    QObject *root;
    QObject *infoText;
    int userMode = BLACK_USER;
    void toggleUserColor(void);
    int checkIsWin(int x, int y);

Q_OBJECT
signals:
    void addPieseSignal(QString objName, int x, int y, QString color);
    void showDialogSignal(QString message);

public slots:
    void mouseClickHandler(int x, int y);
    void resetHandler(void);
};


#endif /* GOMOKU_H */
