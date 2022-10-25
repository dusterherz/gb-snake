#include <gb/gb.h>
#include <gbdk/console.h>
#include <stdio.h>

#include "snake.h"

uint8_t sprite_data[] = {
    0x3C, 0x3C, 0x42, 0x7E, 0x99, 0xFF, 0xA9, 0xFF, 0x89, 0xFF, 0x89,
    0xFF, 0x42, 0x7E, 0x3C, 0x3C, 0x3C, 0x3C, 0x42, 0x7E, 0xB9, 0xFF,
    0x89, 0xFF, 0x91, 0xFF, 0xB9, 0xFF, 0x42, 0x7E, 0x3C, 0x3C, 0x3C,
    0x3C, 0x42, 0x7E, 0x99, 0xFF, 0x89, 0xFF, 0x99, 0xFF, 0x89, 0xFF,
    0x5A, 0x7E, 0x3C, 0x3C, 0x3C, 0x3C, 0x42, 0x7E, 0xA9, 0xFF, 0xA9,
    0xFF, 0xB9, 0xFF, 0x89, 0xFF, 0x42, 0x7E, 0x3C, 0x3C};

SnakeBody snake_body[SNAKE_SIZE] = {
    {4, 2, RIGHT},
    {3, 2, RIGHT},
    {2, 2, RIGHT},
};
joypads_t joypads;

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
  // init controls
  joypad_init(1, &joypads);
}

void move_snake() {
  if (joypads.joy0 & J_UP)
    snake_body[0].dir = UP;
  else if (joypads.joy0 & J_DOWN)
    snake_body[0].dir = DOWN;
  else if (joypads.joy0 & J_LEFT)
    snake_body[0].dir = LEFT;
  else if (joypads.joy0 & J_RIGHT)
    snake_body[0].dir = RIGHT;
  uint8_t i = SNAKE_SIZE;
  while (1) {
    i--;
    if (snake_body[i].dir == RIGHT) {
      snake_body[i].x++;
    } else if (snake_body[i].dir == LEFT) {
      snake_body[i].x--;
    } else if (snake_body[i].dir == UP) {
      snake_body[i].y--;
    } else if (snake_body[i].dir == DOWN) {
      snake_body[i].y++;
    }
    move_sprite(i, snake_body[i].x * 8, snake_body[i].y * 8);
    if (i > 0) {
      snake_body[i].dir = snake_body[i - 1].dir;
    } else {
      break;
    }
  }
}

int main() {
  init_snake();
  while (1) {
    joypad_ex(&joypads);
    // Do something
    move_snake();
    wait_vbl_done();
    wait_vbl_done();
    wait_vbl_done();
    wait_vbl_done();
    wait_vbl_done();
  }
}
