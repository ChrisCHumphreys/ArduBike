#ifndef OBSTACLES_H
#define OBSTACLES_H

#define TILE_SIZE  8

#include<Arduboy2.h>
#include "globals.h"

// Definitions
#define TOP         1
#define BOTTOM      0

/**
 * Constants
 */
const int SCREEN_HEIGHT = 64;
const int SCREEN_WIDTH = 128;
const int RIDER_HEIGHT = 16;

Sprites sprite;
Arduboy2 ab;

int y_location;

const unsigned char PROGMEM low_long_jump[] = {
  0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0x10, 0x10, 0x8, 0x8, 0x4, 0x4, 0x2, 0x2, 0xff, 0x1, 0x1, 0xff, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1, 0x1, 0xfe, 0xff, 0xfd, 0xff, 0xfb, 0xff, 0xf7, 0xff, 0xef, 0xff, 0xdf, 0xff, 0xbf, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1, 0x1, 0xfe, 0xff, 0xfd, 0xff, 0xfb, 0xff, 0xf7, 0xff, 0xef, 0xff, 0xdf, 0xff, 0xbf, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1, 0x1, 0xfe, 0xff, 0xfd, 0xff, 0xfb, 0xff, 0xf7, 0xff, 0xef, 0xff, 0xdf, 0xff, 0xbf, 0xff, 0x7f, 0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0x10, 0x10, 0x8, 0x8, 0x4, 0x4, 0x2, 0x2, 0x1, 0x1, 0x1, 0x1, 0x3, 0x3, 0x7, 0x7, 0xf, 0xf, 0x1f, 0x1f, 0x3f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 
};

const unsigned char PROGMEM bump[] = {
  0x8, 0x8, 0x4, 0x4, 0x2, 0x2, 0xff, 0x1, 0x1, 0xff, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1, 0x1, 0xff, 0xff, 0xfd, 0xff, 0xfb, 0xff, 0xf7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1, 0x1, 0xff, 0xff, 0xfb, 0xff, 0xf7, 0xff, 0xef, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1, 0x1, 0xff, 0xff, 0xfb, 0xff, 0xf7, 0xff, 0xef, 0x8, 0x8, 0x4, 0x4, 0x2, 0x2, 0x1, 0x1, 0x1, 0x1, 0x3, 0x3, 0x7, 0x7, 0xf, 0xf,
};

const unsigned char PROGMEM tall_jump[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0xfe, 0x1, 0x1, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1, 0x1, 0xff, 0xfb, 0xff, 0xef, 0xff, 0xbf, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1, 0x1, 0xff, 0xfd, 0xff, 0xf7, 0xff, 0xdf, 0xff, 0x7e, 0xff, 0xfb, 0xff, 0xef, 0xff, 0xbf, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1, 0x1, 0xff, 0xfd, 0xff, 0xf7, 0xff, 0xdf, 0xff, 0x7f, 0xff, 0xfd, 0xff, 0xf7, 0xff, 0xdf, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x3, 0x1, 0x1, 0x3, 0x7, 0xf, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xf7, 0xff, 0xdf, 0xff, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x3, 0x7, 0xf, 0x1f, 0x3f, 0x7f, 0xff,
};  

const unsigned char PROGMEM tile_sheet[] =
{
// width, height,
8, 8,

// TILE 00 - Empty Lane
// 0##0##0#
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
// 00000000
0x01, 0x01, 0x00, 0x01, 0x01, 0x00, 0x01, 0x00, 

// TILE 01 - Mud Lane
// 0##0##0#
// 00#0#000
// 0#0##0## 
// #0#00#00
// #00#00##
// 0#####0#
// 00#0#0#0
// 00000000
0x19, 0x25, 0x6a, 0x35, 0x67, 0x28, 0x55, 0x34,
 
// TILE 02 - Upper Left bump
// 00000000
// 00000000
// 00000000
// 00000000
// 000000##
// 0000###0
// 00##00#0
// ##0000#0
0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0xf0, 0x10,
 
// TILE 03 - Mid Left bump
// 000000#0
// 000000#0
// 000000#0
// 000000#0
// 000000##
// 000000#0
// 000000#0
// 000000#0
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x10, 

// TILE 04 - bottom left bump
// 000000#0
// 000000#0
// 000000#0
// 000000#0
// 000000##
// 0000##00
// 00##0000
// ##000000
0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0x1f, 0x10,
 
// TILE 05 - Upper Right bump
// 00000000
// 00000000
// 00000000
// 00000000
// ##000000
// 0###0000
// 0#####00
// 0#######
0x10, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80,
 
// TILE 06 - Mid Right Bump
// 0#######
// 0#######
// 0#######
// 0#######
// ########
// 0##0####
// 0####0##
// 0######0
0x10, 0xff, 0xff, 0xdf, 0xff, 0xbf, 0xff, 0x7f,
 
// TILE 07 - bottom right bump
// 0#######
// 0#######
// 0#######
// 0#######
// ########
// 00######
// 0000####
// 000000##
0x10, 0x1f, 0x3f, 0x3f, 0x7f, 0x7f, 0xff, 0xff,
 
// TILE 08 - Left top and bottom of jump extender
// 00000000
// 00000000
// 00000000
// 00000000
// 000000##
// 0000##00
// 00##0000
// ##000000
0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0x10, 0x10, 

// TILE 09 - Rigth top of jump extender
// 00000000
// 00000000
// 00000000
// 00000000
// ##000000
// ####0000
// ######00
// ########
0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 

// TILE 10 - Right bottom of jump extender
// ########
// ########
// ########
// ########
// ########
// 00######
// 0000####
// 000000##
0x1f, 0x1f, 0x3f, 0x3f, 0x7f, 0x7f, 0xff, 0xff,

// TILE 11 - Left Bottom Jump Extender
// ########
// ########
// ########
// ########
// #0######
// ###0####
// #####0##
// #######0
0xff, 0xef, 0xff, 0xdf, 0xff, 0xbf, 0xff, 0x7f,

// TILE 12 - Top Small Steep
// 00000000
// 00000000
// 00000000
// 00000000
// 000##000
// 00#00#00
// 0#0000#0
// #0#00###
0x80, 0x40, 0xa0, 0x10, 0x10, 0xa0, 0xc0, 0x80,

// TILE 13 - Mid Small Steep
// 000000##
// 00#00###
// 000000##
// 00#00###
// 000##0##
// 00#00###
// 000000##
// 00#00##0
0x00, 0x00, 0xaa, 0x10, 0x10, 0xaa, 0xff, 0x7f,
 
// TILE 14 - Bottom Small Steep
// 000000##
// 00#00###
// 000000##
// 00#00###
// 000##0##
// 00#00###
// 0#0000##
// #000000#
0x80, 0x40, 0x2a, 0x10, 0x10, 0x2a, 0x7f, 0xff,

// TILE 15 - Left Extender Steep
// 0000000#
// 000000#0
// 00000#00
// 0000#000
// 000#0000
// 00#00000
// 0#000000
// #0000000
0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01,
 
// TILE 16 Right Extetender Top Steep
// #0000000
// ##000000
// ###00000
// ####0000
// #####000
// ######00
// #######0
// ########
0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80,

// TILE 17 - Right Extender Bottom Steep
// ########
// 0#######
// 00######
// 000#####
// 0000####
// 00000###
// 000000##
// 0000000#
0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff,
 
// TILE 18 - Right Extender Mid Steep
// ########
// #0######
// ########
// ###0####
// ########
// #####0##
// ########
// #######0
0xff, 0xfd, 0xff, 0xf7, 0xff, 0xdf, 0xff, 0x7f,

// TILE 19 - Quick Jump Top
// 0000000#
// 000000#0
// 00000#00
// 0000#000
// 000#0000
// 00#00000
// 0#00000#
// #00000#0
0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x82, 0x41,

// TILE 20 - Quick Jump Mid
// 00000#0#
// 0000#0#0
// 000#0#0#
// 00#0#0#0
// 0#0#0#00
// #0#0#000
// 0#0#0000
// #0#00000
0xa0, 0x50, 0xa8, 0x54, 0x2a, 0x15, 0x0a, 0x05,

// TILE 21 - Quick Jump Top
// 0#00000#
// #00000#0
// 00000#00
// 0000#000
// 000#0000
// 00#00000
// 0#000000
// #0000000
0x82, 0x41, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01, 
};

void draw_bump(int x, int y) {
  sprite.drawSelfMasked(x, y, tile_sheet, 2);
  sprite.drawSelfMasked(x + TILE_SIZE, y, tile_sheet, 5);
  sprite.drawSelfMasked(x, y + (TILE_SIZE * 1), tile_sheet, 3);
  sprite.drawSelfMasked(x + TILE_SIZE, y + (TILE_SIZE * 1), tile_sheet, 6);
  sprite.drawSelfMasked(x, y + (TILE_SIZE * 2), tile_sheet, 3);
  sprite.drawSelfMasked(x + TILE_SIZE, y + (TILE_SIZE * 2), tile_sheet, 6);
  sprite.drawSelfMasked(x, y + (TILE_SIZE * 3), tile_sheet, 3);
  sprite.drawSelfMasked(x + TILE_SIZE, y + (TILE_SIZE * 3), tile_sheet, 6);
  sprite.drawSelfMasked(x, y + (TILE_SIZE * 4), tile_sheet, 4);
  sprite.drawSelfMasked(x + TILE_SIZE, y + (TILE_SIZE * 4), tile_sheet, 7);

}

void draw_flat_jump(int x, int y = 0) {
  draw_bump(x + TILE_SIZE, SCREEN_HEIGHT - (6 * TILE_SIZE) + 3);
  y_location = SCREEN_HEIGHT - ( 6 * TILE_SIZE) + 3;
  sprite.drawSelfMasked(x, y_location + (TILE_SIZE / 2), tile_sheet, 8);
  sprite.drawSelfMasked(x + (TILE_SIZE * 3), y_location + (TILE_SIZE / 2), tile_sheet, 9);
  sprite.drawSelfMasked(x + (TILE_SIZE * 3), y_location + 12, tile_sheet, 11);
  sprite.drawSelfMasked(x + (TILE_SIZE * 3), y_location + 20, tile_sheet, 11);
  sprite.drawSelfMasked(x + (TILE_SIZE * 3), y_location + 28, tile_sheet, 11);
  sprite.drawSelfMasked(x, y_location + 36, tile_sheet, 8);
  sprite.drawSelfMasked(x + (TILE_SIZE * 3), y_location + 36, tile_sheet, 10);
}

void draw_track(int x, int mud_lane) {
  y_location = SCREEN_HEIGHT - ( 4 * TILE_SIZE) - 1;
  for (int i = 0; i < 4; i++) {
    if (i == mud_lane and i < 4) {
      sprite.drawSelfMasked(x, (i * TILE_SIZE) + y_location, tile_sheet, 1);
    } else {
      sprite.drawSelfMasked(x, (i * TILE_SIZE) + y_location, tile_sheet, 0);
    }
  }
}

void draw_steep_short_jump(int x, int y = 1) {
  y_location = SCREEN_HEIGHT - ( 5 * TILE_SIZE) - y;
  sprite.drawSelfMasked(x, y_location, tile_sheet, 12);
  sprite.drawSelfMasked(x, y_location + TILE_SIZE, tile_sheet, 13);
  sprite.drawSelfMasked(x, y_location + (TILE_SIZE * 2), tile_sheet, 13);
  sprite.drawSelfMasked(x, y_location + (TILE_SIZE * 3), tile_sheet, 13);
  sprite.drawSelfMasked(x, y_location + (TILE_SIZE * 4), tile_sheet, 14); 
}

void draw_steep_mid_jump(int x) {
  y_location = SCREEN_HEIGHT - ( 4 * TILE_SIZE);
  draw_steep_short_jump(x + TILE_SIZE, TILE_SIZE);
  sprite.drawSelfMasked(x, y_location + TILE_SIZE, tile_sheet, 15);
  sprite.drawSelfMasked(x + (TILE_SIZE * 2), y_location + TILE_SIZE, tile_sheet, 16);
  sprite.drawSelfMasked(x + (TILE_SIZE * 2), y_location + (TILE_SIZE * 2), tile_sheet, 18);
  sprite.drawSelfMasked(x + (TILE_SIZE * 2), y_location + (TILE_SIZE * 3), tile_sheet, 18);
  sprite.drawSelfMasked(x + (TILE_SIZE * 2), y_location + (TILE_SIZE * 4), tile_sheet, 18);
  sprite.drawSelfMasked(x, y_location + (TILE_SIZE * 5), tile_sheet, 15);
  sprite.drawSelfMasked(x + (TILE_SIZE * 2), y_location + (TILE_SIZE * 5), tile_sheet, 17);
}

void draw_track(int trackName[], unsigned int map_index) {
  int counter = 0;
  int obstacle_offset = 0;
  
  while (*(trackName + counter) != FINISH) {
    if (*(trackName + counter) == CLEAR) {
      draw_track((TILE_SIZE * counter) - map_index + (obstacle_offset * TILE_SIZE), -1);
    } else if (*(trackName + counter) == MUD1) {
      draw_track((TILE_SIZE * counter) - map_index + (obstacle_offset * TILE_SIZE), 0);
    } else if (*(trackName + counter) == MUD2) {
      draw_track((TILE_SIZE * counter) - map_index + (obstacle_offset * TILE_SIZE), 1);
    } else if (*(trackName + counter) == MUD3) {
      draw_track((TILE_SIZE * counter) - map_index + (obstacle_offset * TILE_SIZE), 2);
    } else if (*(trackName + counter) == MUD4) {
      draw_track((TILE_SIZE * counter) - map_index + (obstacle_offset * TILE_SIZE), 3);
    } else if (*(trackName + counter) == BUMP) {
      draw_steep_short_jump((TILE_SIZE * counter) - map_index + (obstacle_offset * TILE_SIZE));
    } else if (*(trackName + counter) == JUMP) {
      draw_steep_mid_jump((TILE_SIZE * counter) - map_index + (obstacle_offset * TILE_SIZE));
      obstacle_offset += 2;
    } else if (*(trackName + counter) == HUMP) {
      draw_flat_jump((TILE_SIZE * counter) - map_index + (obstacle_offset * TILE_SIZE));
      obstacle_offset += 3;
    }
    counter += 1;
    
  }
}


#endif
