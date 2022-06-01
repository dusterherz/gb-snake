#ifndef SNAKE_H
#define SNAKE_H

#include <gb/gb.h>

#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3
#define SNAKE_SIZE 3

typedef struct SnakeBody {
  uint8_t x;
  uint8_t y;
  uint8_t dir;
};

void move_snake();
void init_snake();

#endif  // SNAKE_H
