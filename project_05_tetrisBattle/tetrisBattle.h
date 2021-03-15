#ifndef TETRIS_BATTLE_H
#define TETRIS_BATTLE_H

#include "QObject"
#include "QDebug"


class TetrisBattle : public QObject {
public:
    TetrisBattle(void);    
    ~TetrisBattle(void);    
private:

Q_OBJECT
signals:


public slots:
    void startHandler(void);
    void stopHandler(void);

};


#endif /* TETRIS_BATTLE_H */
