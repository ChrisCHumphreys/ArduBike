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
int surface = FLAT;
int lane = 1;
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
  arduboy.print("\nSurface: ");
  arduboy.print(surface);

  // draw line under game
  arduboy.fillRect(0, SCREEN_HEIGHT-1, SCREEN_WIDTH, 1);

  surface = draw_track(track_1, map_index);

  sprite.drawSelfMasked(4, SCREEN_HEIGHT - 12 - (lane * TILE_SIZE), ardurider, 0);

  if (arduboy.pressed(A_BUTTON)) {
    is_moving = true;
  } else {
    is_moving = false;
  }
  
  if (arduboy.pressed(B_BUTTON) and arduboy.pressed(A_BUTTON)) {
    map_index = 0;
    surface = 0;
    is_moving = false;
  }

 
  if (arduboy.justPressed(UP_BUTTON)) {
    (lane == 4) ? lane = 4 : lane += 1;
  }
    if (arduboy.justPressed(DOWN_BUTTON)) {
    (lane == 1) ? lane = 1 : lane -= 1;
  }
}
