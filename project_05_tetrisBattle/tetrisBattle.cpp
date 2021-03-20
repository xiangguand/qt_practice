#include <string>
#include <cstdlib>
#include <ctime>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include "tetrisBattle.h"

using namespace std;

TetrisBattle::TetrisBattle(QObject *root) {
    qDebug() << "Constructor TetrisBattle";
    this->root = root;
    for(int i=0;i<TETRIS_HEIGHT;i++) {
        for(int j=0;j<TETRIS_WIDTH;j++) {
            this->tetrisMap[i][j] = 0;
        }
    }
    // Initialize the random time seed
    srand(time(NULL));
}

TetrisBattle::TetrisBattle(void) {
    qDebug() << "Constructor TetrisBattle";
}

TetrisBattle::~TetrisBattle(void) {
    qDebug() << "Deconstruct TetrisBattle";
}

void TetrisBattle::gernerateNewTetris(void) {
    int tetris_type = (rand() % TETRIS_TYPE_LEN);  // generate the tetris type
    qDebug() << "Generate the tetris " << this->tetris_decode[tetris_type]; 

    // Define the current tetris coordinate
    memcpy(&this->current_pos, &this->tetrisTypeDefaultPos_decode[tetris_type], sizeof(tetris_pos_t));

    this->each_rect = (rect_pos_t *)&this->current_pos;
    for(int i=0;i<4;i++) {
        TetrisBattle::createRectsignal(QStringLiteral("rect%1").arg(i+this->rectNumbers), 
                                    this->each_rect[i].x, 
                                    this->each_rect[i].y, 
                                    QString::fromLocal8Bit(this->current_pos.color.c_str()));

        qDebug() << this->each_rect[i].x << ", " << this->each_rect[i].y;
    }
    this->rectNumbers += 4;
}

int TetrisBattle::isDownExist(rect_pos_t *pos) {
    if(pos->x >= 0 && pos->y >= 0) {
        if(tetrisMap[pos->x+1][pos->y] == RECT_OK) {
            return 1;
        }
    }
    return false;
}

void TetrisBattle::insertTetris2Map(void) {
    for(int i=0;i<4;i++) {
        tetrisMap[this->each_rect[i].x][this->each_rect[i].y] = RECT_OK;
    }
}

void TetrisBattle::showMap(void) {
    for(int i=0;i<TETRIS_HEIGHT;i++) {
        std::string temp = "";
        for(int j=0;j<TETRIS_WIDTH;j++) {
            temp += std::to_string(this->tetrisMap[i][j]);
            temp += ", ";
        }
        qDebug() <<  QString::fromLocal8Bit(temp.c_str());
    }
}

void TetrisBattle::startHandler(void) {
    qDebug() << "start";
    gernerateNewTetris();
}

void TetrisBattle::stopHandler(void) {
    qDebug() << "stop";
}

void TetrisBattle::keyboardHandler(int dir) {
    int flag_width_exeed = 0;
    this->dir = dir;
    if(this->dir == DIR_PUT) {
        
    }
    else if(this->dir == DIR_DOWN) {
        for(int i=0;i<4;i++) {
            this->each_rect[i].x++;
        }
    }
    else if(this->dir == DIR_LEFT) {
        for(int i=0;i<4;i++) {
            this->each_rect[i].y--;
            if(this->each_rect[i].y < 0) flag_width_exeed = 1;
        }
    }
    else if(this->dir == DIR_RIGHT) {
        for(int i=0;i<4;i++) {
            this->each_rect[i].y++;
            if(this->each_rect[i].y >= 10) flag_width_exeed = 2;
        }
    }

    for(int i=0;i<4;i++) {
        if(tetrisMap[this->each_rect[i].x][this->each_rect[i].y] == RECT_OK) {
            if(this->dir == DIR_LEFT) {
                for(int i=0;i<4;i++) {this->each_rect[i].y++;}
            }
            else {
                for(int i=0;i<4;i++) {this->each_rect[i].y--;}
            }
        }
    }

    if(flag_width_exeed == 1) {
        for(int i=0;i<4;i++) {
            this->each_rect[i].y++;
        }
    }
    else if(flag_width_exeed == 2) {
        for(int i=0;i<4;i++) {
            this->each_rect[i].y--;
        }   
    }

    int flag = false;
    for(int i=0;i<4;i++) {
        if(this->each_rect[i].x >= 19) {
            qDebug() << "Put";
            flag = true;
        }
        QObject *temp = this->root->findChild<QObject *>(QStringLiteral("rect%1").arg(this->rectNumbers-4+i));
        temp->setProperty("y", 50*this->each_rect[i].x);
        temp->setProperty("x", 50*this->each_rect[i].y);
        if(this->each_rect[i].x >= 0 && this->each_rect[i].y >= 0) {
            temp->setProperty("visible", true);
        }
    }
    for(int i=0;i<4;i++) {
        if(TetrisBattle::isDownExist(&each_rect[i])) {
            qDebug() << "Exist";
            flag = true;
        }
    }
    if(flag) {
        insertTetris2Map();
        showMap();
        gernerateNewTetris();
    }
}

void TetrisBattle::updateHandler(void) {
    int flag = false;
    for(int i=0;i<4;i++) {
        this->each_rect[i].x++;
        if(this->each_rect[i].x >= 19) {
            qDebug() << "Put";
            flag = true;
        }
        QObject *temp = this->root->findChild<QObject *>(QStringLiteral("rect%1").arg(this->rectNumbers-4+i));
        temp->setProperty("y", 50*this->each_rect[i].x);
        temp->setProperty("x", 50*this->each_rect[i].y);
        if(this->each_rect[i].x >= 0 && this->each_rect[i].y >= 0) {
            temp->setProperty("visible", true);
        }
    }
    for(int i=0;i<4;i++) {
        if(TetrisBattle::isDownExist(&each_rect[i])) {
            qDebug() << "Exist";
            flag = true;
        }
    }
    if(flag) {
        insertTetris2Map();
        showMap();
        gernerateNewTetris();
    }
}


