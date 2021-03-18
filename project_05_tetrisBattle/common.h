#ifndef COMMON_H
#define COMMON_H

#define TETRIS_WIDTH    (10)
#define TETRIS_HEIGHT   (20)
#define MAX_TETRIS_NUM  (TETRIS_WIDTH*TETRIS_HEIGHT)

enum DIR_ENUM{
    DIR_NONE,
    DIR_UP = 1,
    DIR_DOWN = 2,
    DIR_LEFT = 3,
    DIR_RIGHT = 4,
};

#endif /* COMMON_H */
