#include <string>
#include <cstdlib>
#include <ctime>
#include <QDebug>
#include <vector>

#include "gomoku.h"

Gomoku::Gomoku(QObject *root) {
    qDebug() << "Constructor TetrisBattle";
    this->root = root;
    this->infoText = this->root->findChild<QObject *>("infoWindow")->findChild<QObject *>("infoText");
    if(this->infoText != NULL) {
        qDebug() << "Find infoText !!!";
    }
    Gomoku::clearMap();
}

Gomoku::Gomoku(void) {
    qDebug() << "Constructor TetrisBattle";
    Gomoku::clearMap();
}

Gomoku::~Gomoku(void) {
    qDebug() << "Deconstruct TetrisBattle";
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

QString Gomoku::toggleUserColor(void) {
    QString temp = gomoku_color[this->userMode];
    if(this->userMode == BLACK_USER) {
        this->userMode = WHITE_USER;
    }
    else if(this->userMode == WHITE_USER) {
        this->userMode = BLACK_USER;
    }
    this->infoText->setProperty("text", "Now: " + gomoku_color[this->userMode]);
    return temp;
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
            return;
        }
        this->gomokuMap[map_y][map_x] = this->userMode;
        addPieseSignal(objName, set_x, set_y, Gomoku::toggleUserColor());
        this->collectPiece.push_back(objName);
        this->pieceCnt++;
        Gomoku::showMap();
    }
}


void Gomoku::resetHandler(void) {
    qDebug() << "reset";
    Gomoku::init();
}
