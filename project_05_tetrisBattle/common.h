#ifndef COMMON_H
#define COMMON_H

#include <string>

#define TETRIS_WIDTH     (10)
#define TETRIS_HEIGHT    (20)
#define MAX_TETRIS_NUM   (TETRIS_WIDTH*TETRIS_HEIGHT)
#define TETRIS_TYPE_LEN  (7)

enum DIR_ENUM {
    DIR_NONE,
    DIR_CW = 1,     // Key: up
    DIR_DOWN = 2,   // Key: down
    DIR_LEFT = 3,   // Key: left
    DIR_RIGHT = 4,  // Key: right
    DIR_PUT = 5,    // Key: x
    DIR_HOLD = 6,   // Key: c
    DIR_CCW = 7,    // Key: z
};

enum MAP_STATE {
    RECT_NONE = 0,
    RECT_OK = 1,
};

enum TETRIS_TYPE {
    TETRIS_TYPE_NONE = -1,
    TETRIS_TYPE_I = 0, 
    TETRIS_TYPE_J = 1,
    TETRIS_TYPE_L = 2,
    TETRIS_TYPE_O = 3,
    TETRIS_TYPE_S = 4,
    TETRIS_TYPE_T = 5,
    TETRIS_TYPE_Z = 6,
};

typedef struct _rect_pos_t {
    int x;
    int y;
}rect_pos_t;

typedef struct _tetris_pos_t {
    rect_pos_t rect1;
    rect_pos_t rect2;
    rect_pos_t rect3;
    rect_pos_t rect4;
    std::string color;
}tetris_pos_t;

// Define the default tetris position
#define I_DEFAULT_POS {      \
    .rect1 = {               \
        .x = -3,             \
        .y = 5,              \
    },                       \
    .rect2 = {               \
        .x = -2,             \
        .y = 5,              \
    },                       \
    .rect3 = {               \
        .x = -1,             \
        .y = 5,              \
    },                       \
    .rect4 = {               \
        .x = 0,              \
        .y = 5,              \
    },                       \
    .color = "blue",         \
}                            \

#define J_DEFAULT_POS {      \
    .rect1 = {               \
        .x = -2,             \
        .y = 5,              \
    },                       \
    .rect2 = {               \
        .x = -1,             \
        .y = 5,              \
    },                       \
    .rect3 = {               \
        .x = 0,              \
        .y = 5,              \
    },                       \
    .rect4 = {               \
        .x = 0,              \
        .y = 4,              \
    },                       \
    .color = "blue",         \
}                            \

#define L_DEFAULT_POS {      \
    .rect1 = {               \
        .x = -2,             \
        .y = 4,              \
    },                       \
    .rect2 = {               \
        .x = -1,             \
        .y = 4,              \
    },                       \
    .rect3 = {               \
        .x = 0,              \
        .y = 4,              \
    },                       \
    .rect4 = {               \
        .x = 0,              \
        .y = 5,              \
    },                       \
    .color = "orange",       \
}                            \

#define O_DEFAULT_POS {      \
    .rect1 = {               \
        .x = -1,             \
        .y = 4,              \
    },                       \
    .rect2 = {               \
        .x = -1,             \
        .y = 5,              \
    },                       \
    .rect3 = {               \
        .x = 0,              \
        .y = 4,              \
    },                       \
    .rect4 = {               \
        .x = 0,              \
        .y = 5,              \
    },                       \
    .color = "yellow",       \
}                            \

#define S_DEFAULT_POS {      \
    .rect1 = {               \
        .x = -1,             \
        .y = 6,              \
    },                       \
    .rect2 = {               \
        .x = -1,             \
        .y = 5,              \
    },                       \
    .rect3 = {               \
        .x = 0,              \
        .y = 5,              \
    },                       \
    .rect4 = {               \
        .x = 0,              \
        .y = 4,              \
    },                       \
    .color = "green",        \
}                            \

#define T_DEFAULT_POS {      \
    .rect1 = {               \
        .x = -1,             \
        .y = 4,              \
    },                       \
    .rect2 = {               \
        .x = 0,              \
        .y = 3,              \
    },                       \
    .rect3 = {               \
        .x = 0,              \
        .y = 4,              \
    },                       \
    .rect4 = {               \
        .x = 0,              \
        .y = 5,              \
    },                       \
    .color = "purple",       \
}                            \

#define Z_DEFAULT_POS {      \
    .rect1 = {               \
        .x = -1,             \
        .y = 3,              \
    },                       \
    .rect2 = {               \
        .x = -1,             \
        .y = 4,              \
    },                       \
    .rect3 = {               \
        .x = 0,              \
        .y = 4,              \
    },                       \
    .rect4 = {               \
        .x = 0,              \
        .y = 5,              \
    },                       \
    .color = "red",          \
}                            \

#define ROTATE_COR_REF      (2)   // Rotate the rect3 coordinate

#define CW_MATRIX           {{0, -1}, {1, 0}}
#define CCW_MATRIX          {{0, 1}, {-1, 0}}

#endif /* COMMON_H */
