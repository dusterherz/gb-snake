#include <gb/gb.h>
#include <gbdk/console.h>
#include <stdio.h>

#include "joypad.h"
#include "snake.h"

void init_graphics() {
  // init palettes
  BGP_REG = OBP0_REG = OBP1_REG = 0xE4;
  // init display
  SHOW_BKG;
  SHOW_SPRITES;
}

int main() {
  init_graphics();
  init_snake();
  init_joypad();
  while (1) {
    // Do something
    read_joypad();
    move_snake();
    wait_vbl_done();
  }
}
