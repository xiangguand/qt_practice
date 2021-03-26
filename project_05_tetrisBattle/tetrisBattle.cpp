#include <string>
#include <cstdlib>
#include <ctime>
#include <QDebug>
#include <vector>

#include "tetrisBattle.h"
#include "support_math.h"

using namespace std;

std::vector<std::vector <int>> rotate_cw_matrix CW_MATRIX;
std::vector<std::vector <int>> rotate_ccw_matrix CCW_MATRIX;

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
    this->current_tetris_type = (rand() % TETRIS_TYPE_LEN);  // generate the tetris type
    qDebug() << "Generate the tetris " << this->tetris_decode[this->current_tetris_type]; 

    // Define the current tetris coordinate
    this->current_pos = this->tetrisTypeDefaultPos_decode[this->current_tetris_type];

    this->each_rect = (rect_pos_t *)&this->current_pos;
    for(int i=0;i<4;i++) {
        qDebug() << this->each_rect[i].x << ", " << this->each_rect[i].y;
    }
}

void TetrisBattle::gernerateNewTetris(int tetris_type) {
    this->current_tetris_type = tetris_type;  // generate the tetris type
    qDebug() << "Generate the tetris " << this->tetris_decode[this->current_tetris_type]; 

    // Define the current tetris coordinate
    this->current_pos = this->tetrisTypeDefaultPos_decode[this->current_tetris_type];

    this->each_rect = (rect_pos_t *)&this->current_pos;
    for(int i=0;i<4;i++) {
        qDebug() << this->each_rect[i].x << ", " << this->each_rect[i].y;
    }
}

int TetrisBattle::isDownExist(rect_pos_t *pos) {
    if(pos->x >= 0 && pos->y >= 0) {
        if(tetrisMap[pos->x+1][pos->y] > 0) {
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

void TetrisBattle::handleKeyPut(void) {
    for(int i=0;i<4;i++) {
        QObject *temp = this->root->findChild<QObject *>(QStringLiteral("rect%1").arg(this->each_rect[i].x+this->each_rect[i].y*TETRIS_HEIGHT));
        if(temp != NULL) {
            if(this->each_rect[i].x >= 0 && this->each_rect[i].y >= 0) {
                temp->setProperty("visible", false);
            }
        }
        else {
            qDebug() << "NULL Object";
        }
    }
    int flag = false;
    while(!flag) {
        for(int i=0;i<4;i++) { 
            this->each_rect[i].x++; 
            if(this->each_rect[i].x >= 19) {
                flag = true;
            }
        }
        for(int i=0;i<4;i++) {
            if(TetrisBattle::isDownExist(&this->each_rect[i])) {
                flag = true;
            }
        }
    }
    
    for(int i=0;i<4;i++) {
        QObject *temp = this->root->findChild<QObject *>(QStringLiteral("rect%1").arg(this->each_rect[i].x+this->each_rect[i].y*TETRIS_HEIGHT));
        if(temp != NULL) {
            if(this->each_rect[i].x >= 0 && this->each_rect[i].y >= 0) {
                temp->setProperty("visible", true);
                temp->setProperty("color", tetrisTypeColor_decode[this->current_tetris_type]);
            }
        }
        else {
            qDebug() << "NULL Object";
        }
    }
    insertTetris2Map();
    showMap();
    gernerateNewTetris();
    checkLines();
}


void TetrisBattle::handleKeyCW_CCW(int cw_ccw_mode) {
    std::vector<std::vector<int>> rawCoor = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
    std::vector<int> refCoor = {this->each_rect[ROTATE_COR_REF].x, this->each_rect[ROTATE_COR_REF].y};
    for(std::vector<int>::size_type i=0;i<rawCoor.size();i++) {
        rawCoor[i][0] = this->each_rect[i].x - refCoor[0];
        rawCoor[i][1] = this->each_rect[i].y - refCoor[1];
    }
    std::vector<std::vector<int>> rotateCor = rawCoor;
    if(cw_ccw_mode == CW_MODE) {
        rotateCor = matmul(rawCoor, rotate_cw_matrix);
    }
    else if(cw_ccw_mode == CCW_MODE){
        rotateCor = matmul(rawCoor, rotate_ccw_matrix);
    }

    // find the mimimun and maximum
    int minX;
    int maxX;
    int minY;
    int maxY;
    for(std::vector<int>::size_type i=0;i<rotateCor.size();i++) {
        rotateCor[i][0] += refCoor[0];
        rotateCor[i][1] += refCoor[1];
        if(i == 0) {
            minX = rotateCor[i][1];
            maxX = rotateCor[i][1];

            minY = rotateCor[i][0];
            maxY = rotateCor[i][0];
        }
        if(rotateCor[i][1] < minX){
            minX = rotateCor[i][1];
        }
        if(rotateCor[i][1] > maxX){
            maxX = rotateCor[i][1];
        }
        if(rotateCor[i][0] < minY){
            minY = rotateCor[i][0];
        }
        if(rotateCor[i][0] > maxY){
            maxY = rotateCor[i][0];
        }
    }

    // check the border
    if(maxX >= TETRIS_WIDTH) {
        for(int i=0;i<4;i++) {
            rotateCor[i][1] -= (maxX - TETRIS_WIDTH + 1);
        }
    }
    else if(minX < 0) {
        for(int i=0;i<4;i++) {
            rotateCor[i][1] += (-minX);
        }
    }
    if(maxY >= TETRIS_WIDTH) {
        for(int i=0;i<4;i++) {
            rotateCor[i][0] -= (maxY - TETRIS_WIDTH + 1);
        }
    }
    else if(minY < 0) {
        for(int i=0;i<4;i++) {
            rotateCor[i][0] += (-minY);
        }
    }

    // TODO: check the exist rectangle


    // update the current tetris
    for(std::vector<int>::size_type i=0;i<rotateCor.size();i++) {
        this->each_rect[i].x = rotateCor[i][0];
        this->each_rect[i].y = rotateCor[i][1];
    }
}

void TetrisBattle::handleKeyHold(void) {
    for(int i=0;i<4;i++) {
        QObject *temp = this->root->findChild<QObject *>(QStringLiteral("rect%1").arg(this->each_rect[i].x+this->each_rect[i].y*TETRIS_HEIGHT));
        if(this->each_rect[i].x >= 0 && this->each_rect[i].y >= 0) {
            temp->setProperty("visible", false);
        }
    }
    int temp_tetris_type = this->hold_tetris_type;
    this->hold_tetris_type = this->current_tetris_type;
    // First time
    if(hold_tetris_type == -1) {
        gernerateNewTetris();
    }
    else {
        gernerateNewTetris(temp_tetris_type);
    }
}

void TetrisBattle::checkLines(void) {
    int lines = 0;
    vector<uint8_t> whichLine;
    vector<uint8_t> cutRow;
    int last = 0;
    
    for(int l=TETRIS_HEIGHT-1;l>0;l--) {
        if(sumInt(&this->tetrisMap[l][0], TETRIS_WIDTH) == TETRIS_WIDTH) {
            lines++;
            whichLine.push_back(l);
            if(l == 0) {last = l;}
            else {
                if(l - last != 1) {
                    cutRow.push_back(l);
                }
                last = l;
            }
        }
    }

    // update the score
    this->score += lines;
    QObject *obj = this->root->findChild<QObject *>("txt_score");
    if(obj != NULL) {
        obj->setProperty("text", QStringLiteral("score: %1").arg(this->score));
    }
    
    if(lines > 0) {
        QObject *temp;
        for(std::vector<int>::size_type l=0;l<whichLine.size();l++) {
            for(int c=0;c<TETRIS_WIDTH;c++) {
                temp = this->root->findChild<QObject *>(QStringLiteral("rect%1").arg(whichLine[l]+c*TETRIS_HEIGHT));
                temp->setProperty("visible", false);
                // clear the map
                this->tetrisMap[whichLine[l]][c] = RECT_NONE;
            }
        }

        // offset the map
        // down offset
        string strTemp = "";
        int incLine[TETRIS_HEIGHT];
        for(int i=0;i<TETRIS_HEIGHT;i++) {
            int cnt = 0;
            for(std::vector<int>::size_type l=0;l<whichLine.size();l++) {
                if(i <= whichLine[l]) {
                    cnt++;
                }
                else if(l > whichLine[0]) {   // l more than the biggest whichLine
                    cnt++;
                }
            }
            incLine[i] = cnt;
            strTemp += to_string(i) + ": " + to_string(cnt) + "  ||  ";
        }
        qDebug() <<QString::fromLocal8Bit(strTemp.c_str());

        for(int i=whichLine[0];i>=0;i--) {
            for(int j=0;j<TETRIS_WIDTH;j++) {
                if(this->tetrisMap[i][j] == RECT_OK) {
                    int downL = incLine[i];
                    if(i+downL < TETRIS_HEIGHT) {
                        this->tetrisMap[i][j] = RECT_NONE;
                        this->tetrisMap[i+downL][j] = RECT_OK;
                        temp = this->root->findChild<QObject *>(QStringLiteral("rect%1").arg(i+j*TETRIS_HEIGHT));
                        temp->setProperty("visible", false);
                        QVariant clr = temp->property("color");
                        temp = this->root->findChild<QObject *>(QStringLiteral("rect%1").arg(i+downL+j*TETRIS_HEIGHT));
                        temp->setProperty("visible", true);
                        temp->setProperty("color", clr);
                    }
                }
            }
        }

        // update the whole map

    }
}

 // ============================================= Handle the signal =============================================

void TetrisBattle::startHandler(void) {
    qDebug() << "start";
    for(int i=0;i<TETRIS_WIDTH;i++) {
        for(int j=0;j<TETRIS_HEIGHT;j++) {
            TetrisBattle::createRectSignal(QStringLiteral("rect%1").arg(j+i*TETRIS_HEIGHT), 
                                            i*50, 
                                            j*50, 
                                            "black");
        }
    }
    gernerateNewTetris();
}

void TetrisBattle::stopHandler(void) {
    qDebug() << "stop";
}

void TetrisBattle::keyboardHandler(int dir) {
    for(int i=0;i<4;i++) {
        if(this->each_rect[i].x >= 0 && this->each_rect[i].y >= 0) {
            QObject *temp = this->root->findChild<QObject *>(QStringLiteral("rect%1").arg(this->each_rect[i].x+this->each_rect[i].y*TETRIS_HEIGHT));
            if(temp != NULL) {
                if(this->each_rect[i].x >= 0 && this->each_rect[i].y >= 0) {
                    temp->setProperty("visible", false);
                }
            }
            else {
                qDebug() << "NULL Object";
            }
        }
    }
    int flag_width_exeed = 0;
    this->dir = dir;
    if(this->dir == DIR_PUT) {
        handleKeyPut();
        return;
    }
    else if(this->dir == DIR_CW) {
        TetrisBattle::handleKeyCW_CCW(CW_MODE);
    }
    else if(this->dir == DIR_CCW) {
        TetrisBattle::handleKeyCW_CCW(CCW_MODE);
    }
    else if(this->dir == DIR_HOLD) {
        TetrisBattle::handleKeyHold();
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
        QObject *temp = this->root->findChild<QObject *>(QStringLiteral("rect%1").arg(this->each_rect[i].x+this->each_rect[i].y*TETRIS_HEIGHT));
        if(this->each_rect[i].x >= 0 && this->each_rect[i].y >= 0) {
            temp->setProperty("visible", true);
            temp->setProperty("color", tetrisTypeColor_decode[this->current_tetris_type]);
        }
    }
    for(int i=0;i<4;i++) {
        if(TetrisBattle::isDownExist(&each_rect[i])) {
            qDebug() << "Exist";
            flag = true;
        }
    }
    if(flag) {
        // showMap();
        insertTetris2Map();
        gernerateNewTetris();
        checkLines();
    }
}

void TetrisBattle::updateHandler(void) {
    for(int i=0;i<4;i++) {
        if(this->each_rect[i].x >= 0 && this->each_rect[i].y >= 0) {
            QObject *temp = this->root->findChild<QObject *>(QStringLiteral("rect%1").arg(this->each_rect[i].x+this->each_rect[i].y*TETRIS_HEIGHT));
            if(temp != NULL) {
                if(this->each_rect[i].x >= 0 && this->each_rect[i].y >= 0) {
                    temp->setProperty("visible", false);
                }
            }
            else {
                qDebug() << "NULL Object";
            }
        }
    }
    int flag = false;
    for(int i=0;i<4;i++) {
        this->each_rect[i].x++;
        if(this->each_rect[i].x >= 19) {
            qDebug() << "Put";
            flag = true;
        }
        QObject *temp = this->root->findChild<QObject *>(QStringLiteral("rect%1").arg(this->each_rect[i].x+this->each_rect[i].y*TETRIS_HEIGHT));
        if(this->each_rect[i].x >= 0 && this->each_rect[i].y >= 0) {
            temp->setProperty("visible", true);
            temp->setProperty("color", tetrisTypeColor_decode[this->current_tetris_type]);
        }
    }
    for(int i=0;i<4;i++) {
        if(TetrisBattle::isDownExist(&each_rect[i])) {
            qDebug() << "Exist";
            flag = true;
        }
    }
    if(flag) {
        // showMap();
        insertTetris2Map();
        gernerateNewTetris();
        checkLines();
    }
}


