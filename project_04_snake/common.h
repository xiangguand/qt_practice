#ifndef COMMON_H
#define COMMON_H

enum DIR_ENUM{
    DIR_NONE,
    DIR_UP = 1,
    DIR_DOWN = 2,
    DIR_LEFT = 3,
    DIR_RIGHT = 4,
};

/* Define the default value */
#define SNAKE_DEFAULT_DIR   DIR_RIGHT

typedef struct _snake_pos_ {
    int x;
    int y;
}snake_pos_t;

#endif /* COMMON_H */
