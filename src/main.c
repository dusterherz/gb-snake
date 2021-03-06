#include <gb/gb.h>
#include <gbdk/console.h>
#include <stdio.h>

#include "snake.h"

uint8_t snake_x, snake_y = 0;
uint8_t dir = RIGHT;

uint8_t sprite_data[] = {
    0x3C, 0x3C, 0x42, 0x7E, 0x99, 0xFF, 0xA9, 0xFF, 0x89, 0xFF, 0x89,
    0xFF, 0x42, 0x7E, 0x3C, 0x3C, 0x3C, 0x3C, 0x42, 0x7E, 0xB9, 0xFF,
    0x89, 0xFF, 0x91, 0xFF, 0xB9, 0xFF, 0x42, 0x7E, 0x3C, 0x3C, 0x3C,
    0x3C, 0x42, 0x7E, 0x99, 0xFF, 0x89, 0xFF, 0x99, 0xFF, 0x89, 0xFF,
    0x5A, 0x7E, 0x3C, 0x3C, 0x3C, 0x3C, 0x42, 0x7E, 0xA9, 0xFF, 0xA9,
    0xFF, 0xB9, 0xFF, 0x89, 0xFF, 0x42, 0x7E, 0x3C, 0x3C};

struct SnakeBody snake_body[] = {{4, 2, RIGHT}, {3, 2, RIGHT}, {2, 2, RIGHT}};
uint8_t snake_size = 3;

void init_snake() {
  // init palettes
  BGP_REG = OBP0_REG = OBP1_REG = 0xE4;
  // init sprites
  set_sprite_data(0, 4, sprite_data);
  set_sprite_tile(0, 0);
  set_sprite_tile(1, 1);
  set_sprite_tile(2, 2);
  move_sprite(0, snake_body[0].x, snake_body[0].y);
  move_sprite(1, snake_body[1].x, snake_body[1].y);
  move_sprite(2, snake_body[2].x, snake_body[2].y);
  // init display
  SHOW_BKG;
  SHOW_SPRITES;
}

void move_snake() {
  for (uint8_t i = 0; i < snake_size; i++) {
    switch (snake_body[i].dir) {
      case RIGHT:
        snake_body[i].x++;
        break;
      case LEFT:
        snake_body[i].x--;
        break;
      case UP:
        snake_body[i].y--;
        break;
      case DOWN:
        snake_body[i].y++;
        break;
    }
    /* This code is not working
     All the dir values will be the same at the end, not changing one by one
     if (i > 0) {
       snake_body[i].dir = snake_body[i - 1].dir;
     }*/
    move_sprite(i, snake_body[i].x * 8, snake_body[i].y * 8);
  }
}

int main() {
  init_snake();
  while (1) {
    // Do something
    move_snake();
    wait_vbl_done();
  }
}
