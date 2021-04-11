#include <string>
#include <cstdlib>
#include <ctime>
#include <QDebug>
#include <vector>

#include "gomoku.h"

Gomoku::Gomoku(QObject *root) {
    qDebug() << "Constructor Gomoku";
    this->root = root;
    this->infoText = this->root->findChild<QObject *>("infoWindow")->findChild<QObject *>("infoText");
    if(this->infoText != NULL) {
        qDebug() << "Find infoText !!!";
    }
    Gomoku::clearMap();
}

Gomoku::Gomoku(void) {
    qDebug() << "Constructor Gomoku";
    Gomoku::clearMap();
}

Gomoku::~Gomoku(void) {
    qDebug() << "Deconstruct Gomoku";
}

void Gomoku::init(void) {
    this->pieceCnt = 0;
    this->userMode = BLACK_USER;
    Gomoku::clearMap();
    this->infoText->setProperty("text", "Now: " + gomoku_color[this->userMode]);
}

void Gomoku::clearMap(void) {
    memset(this->gomokuMap, GOMOKU_MAP_NONE, sizeof(gomokuMap));
}

void Gomoku::showMap(void) {
    for(int i=0;i<GOMOKU_WIDTH;i++) {
        std::string temp = "";
        for(int j=0;j<GOMOKU_HEIGHT;j++) {
            temp += std::to_string(this->gomokuMap[i][j]);
            temp += ", ";
        }
        qDebug() << QString::fromLocal8Bit(temp.c_str());
    }
}

void Gomoku::toggleUserColor(void) {
    if(this->userMode == BLACK_USER) {
        this->userMode = WHITE_USER;
    }
    else if(this->userMode == WHITE_USER) {
        this->userMode = BLACK_USER;
    }
    this->infoText->setProperty("text", "Now: " + gomoku_color[this->userMode]);
}

int Gomoku::checkIsWin(int x, int y) {
    // Check the four direction, horizontal, vertical and Diagnal
    int cnt = 1;
    int current_user = this->userMode;
    
    // horizontal
    for(int i=x+1;i<GOMOKU_WIDTH;i++) {
        if(this->gomokuMap[y][i] == current_user) {
            cnt++;
        }
        else {
            break;
        }
    }
    for(int i=x-1;i>=0;i--) {
        if(this->gomokuMap[y][i] == current_user) {
            cnt++;
        }
        else {
            break;
        }
    }
    qDebug() << "horizontal count:" << cnt;
    if(cnt >= 5) {
        return current_user;
    }
    /* ================================================= */
    // vertical
    cnt = 1;
    for(int j=y+1;j<GOMOKU_HEIGHT;j++) {
        if(this->gomokuMap[j][x] == current_user) {
            cnt++;
        }
        else {
            break;
        }
    }
    for(int j=y-1;j>=0;j--) {
        if(this->gomokuMap[j][x] == current_user) {
            cnt++;
        }
        else {
            break;
        }
    }
    qDebug() << "vertical count:" << cnt;
    if(cnt >= 5) {
        return current_user;
    }

    /* ================================================= */
    // diagonal 1
    int tempx, tempy, temp_cnt;
    cnt = 1;
    tempx = x;
    tempy = y;
    temp_cnt = 1;
    while(((tempx+temp_cnt)<GOMOKU_WIDTH) && ((tempy+temp_cnt)<GOMOKU_HEIGHT)) {
        if(this->gomokuMap[tempy+temp_cnt][tempx+temp_cnt] == current_user) {
            cnt++;
        }
        else {
            break;
        }
        temp_cnt++;
    }
    qDebug() << cnt;
    temp_cnt = 1;
    while(((tempx-temp_cnt)>=0) && ((tempy-temp_cnt)>=0)) {
        if(this->gomokuMap[tempy-temp_cnt][tempx-temp_cnt] == current_user) {
            cnt++;
        }
        else {
            break;
        }
        temp_cnt++;
    }
    qDebug() << "diagonal 1 count:" << cnt;
    if(cnt >= 5) {
        return current_user;
    }

    /* ================================================= */
    // diagonal 2
    cnt = 1;
    tempx = x;
    tempy = y;
    temp_cnt = 1;
    while(((tempx-temp_cnt)>=0) && ((tempy+temp_cnt)<GOMOKU_HEIGHT)) {
        if(this->gomokuMap[tempy+temp_cnt][tempx-temp_cnt] == current_user) {
            cnt++;
        }
        else {
            break;
        }
        temp_cnt++;
    }
    qDebug() << cnt;
    temp_cnt = 1;
    while(((tempx+temp_cnt)<GOMOKU_WIDTH) && ((tempy-temp_cnt)>=0)) {
        if(this->gomokuMap[tempy-temp_cnt][tempx+temp_cnt] == current_user) {
            cnt++;
        }
        else {
            break;
        }
        temp_cnt++;
    }
    qDebug() << "diagonal 2 count:" << cnt;
    if(cnt >= 5) {
        return current_user;
    }

    return NONE_USER;
}

void Gomoku::mouseClickHandler(int x, int y) {
    qDebug() << "mouse click: " << x << ", " << y;
    int set_x = PIECE_SIZE * (int) ((x + (PIECE_SIZE >> 1)) / PIECE_SIZE);
    int set_y = PIECE_SIZE * (int) ((y + (PIECE_SIZE >> 1)) / PIECE_SIZE);
    
    if(set_x < GOMOKU_WINDOW_LEN && set_y < GOMOKU_WINDOW_LEN && set_x >= GOMOKU_WIDTH && set_y >= GOMOKU_HEIGHT) {
        QString objName = QStringLiteral("%1").arg(this->pieceCnt);
        int map_x = (int)(set_x / 50) - 1;
        int map_y = (int)(set_y / 50) - 1;
        qDebug() << map_x << ", " << map_y;
        if(this->gomokuMap[map_y][map_x] != GOMOKU_MAP_NONE) {   // exist
            showDialogSignal("Can not place here");
            return;
        }
        this->gomokuMap[map_y][map_x] = this->userMode;
        addPieseSignal(objName, set_x, set_y, gomoku_color[this->userMode]);
        int winUser = Gomoku::checkIsWin(map_x, map_y);
        if(winUser != NONE_USER) {
            showDialogSignal(gomoku_color[winUser] + " win !!!");
        }
        this->collectPiece.push_back(objName);
        this->pieceCnt++;
        Gomoku::toggleUserColor();
        Gomoku::showMap();
    }
}


void Gomoku::resetHandler(void) {
    qDebug() << "reset";
    Gomoku::init();
}
