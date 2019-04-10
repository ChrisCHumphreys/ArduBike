/**
 * @file ardubike.ino
 * @author Chris Humphreys
 * @date 04/05/19
 * 
 * This is the main logic and launcher for the Ardubike arduboy game.
 */


#include <Arduboy2.h>
#include "sprites.h"
#include "tracks.h"
#include "obstacles.h"

/**
 * Gameplay States
 */
#define GAME_TITLE      0
#define GAME_PLAY       1
#define GAME_OVER       2

/**
 * Levels
 */
#define LEVEL_INFINITE  0

int gamestate = GAME_TITLE;
int frame = 0;
bool is_moving = false;
unsigned int map_index = 0;

Arduboy2 arduboy;


void title_screen();
void gmae_play();


void setup() {
  arduboy.begin();
  arduboy.setFrameRate(60);
  arduboy.clear();
}

void loop() {
  if (!(arduboy.nextFrame())) return;
  arduboy.pollButtons();
  
  switch(gamestate) {
    case GAME_TITLE:
      title_screen();
      break;
    case GAME_PLAY:
      game_play();
      break;
  }

  arduboy.display();
}

void title_screen() {
  arduboy.clear();
  arduboy.print("Sprite and tile Demo\n");
  arduboy.print("Press A for Demo");
    if (arduboy.justPressed(A_BUTTON)) {
    gamestate = GAME_PLAY;
  }
}

void game_play() {
  arduboy.clear();

  if (is_moving == true) {
    map_index += 1;
  }

  arduboy.print("Map Index: ");
  arduboy.print(map_index);
  arduboy.print(" : ");

  for (int i = 0; i < 15; i ++) {
    arduboy.print(*(track_1 + i));
  }

  // draw line under game
  arduboy.fillRect(0, SCREEN_HEIGHT-1, SCREEN_WIDTH, 1);

  draw_track(track_1, map_index);
  
//  for (int i = 0; i < (TILE_SIZE * 3); i += TILE_SIZE) {
//    draw_track(i - map_index, -1);
//  };
//
//  //(frame == 47) ? frame = 0 : frame += 1;
//  //sprite.drawSelfMasked(0, 0, ardurider, frame/12);
//  
//  draw_steep_short_jump((TILE_SIZE * 3) - map_index);
//
//  for (int i = TILE_SIZE * 4; i < (TILE_SIZE * 8); i += TILE_SIZE) {
//    draw_track(i - map_index, -1);
//  };
//
//  draw_steep_mid_jump((TILE_SIZE * 8) - map_index);
//    
//  draw_track((TILE_SIZE * 11) - map_index, -1);
//  draw_track((TILE_SIZE * 12) - map_index, 0);
//  draw_track((TILE_SIZE * 13) - map_index, 1);
//  draw_track((TILE_SIZE * 14) - map_index, 2);
//  draw_track((TILE_SIZE * 15) - map_index, 3);

  if (arduboy.pressed(A_BUTTON)) {
    is_moving = true;
  } else {
    is_moving = false;
  }

  if (arduboy.pressed(B_BUTTON) and arduboy.pressed(A_BUTTON)) {
    map_index = 0;
    is_moving = false;
  }
  


//  draw_clear_track()
//  draw_bump(10, 10);
//  draw_jump(30, 10);
//  draw_clear_track(80, 10, -1);
//  draw_steep_short(90, 10);
//  draw_steep_mid(100, 10);
}
