// Chris Humphreys
// April 05, 2019
// Ardubike Game

#include <Arduboy2.h>
#include "sprites.h"
#include "tracks.h"

#define GAME_TITLE      0
#define GAME_PLAY       1
#define GAME_OVER       2
#define LEVEL_INFINITE  0
#define LEVEL_1         1
#define CURRENT_TRACK   track1

Arduboy2 arduboy;

const int SCREEN_HEIGHT = 64;
const int SCREEN_WIDTH = 128;
const int rider_height = 16;
const int MAX_NUM_OF_OBSTACLES = 6;

struct random_obstacle {
  int obstacle_type;
  int obstacle_lane;
  int obstacle_x;
  bool isActive;
};

int lane_shift = 0;
int up = 1;
int down = -1;
int scroll_offset = 0;
int rand_0_4 = 0;
int num_of_puddles = 0;
int track_index = 0;
int gamestate = GAME_TITLE;
int mode = LEVEL_1;
int obstacle_count = 0;

random_obstacle current_obstacles[MAX_NUM_OF_OBSTACLES];

void change_lanes(int);
void scroll_road();
void draw_mapped_obstacle(int obstacle, int index_offset, int lane);
void draw_random_obstacle(int obstacle, int x, int lane);
void title_screen();
void game_play(int mode);

void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.setFrameRate(60);
  // TODO: use initRandomSeed after user presses a button
  arduboy.initRandomSeed();
  //rand_0_4 = random(5);
  
  arduboy.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!(arduboy.nextFrame())) return;
  arduboy.pollButtons();
  
  switch(gamestate) {
    case GAME_TITLE:
      title_screen();
      break;
    case GAME_PLAY:
      game_play(mode);
      break;
  }
  
  
  arduboy.display();
}

void change_lanes(int direction) {
  // if user wants to move down and not in bottom lane
  if (direction < 0 and lane_shift > 0) {
    lane_shift -= 8;
  }
  if (direction > 0 and lane_shift < 24) {
    lane_shift += 8;
  }
}

void scroll_road() {
  scroll_offset = scroll_offset - 1;
  if (scroll_offset == -8) {
    scroll_offset = 0;
  }
}

void draw_mapped_obstacle(int obstacle, int index_offset, int lane) {
  arduboy.drawBitmap(SCREEN_WIDTH + (index_offset * TRACK_ITEM_SIZE) - track_index, SCREEN_HEIGHT - (lane * TRACK_ITEM_SIZE), mud_tile, TRACK_ITEM_SIZE, TRACK_ITEM_SIZE, WHITE);
}

void draw_random_obstacle(int obstacle, int x, int lane) {
  arduboy.drawBitmap(x, SCREEN_HEIGHT - (lane * TRACK_ITEM_SIZE), mud_tile, TRACK_ITEM_SIZE, TRACK_ITEM_SIZE, WHITE);
}

void title_screen() {
   arduboy.clear();
   track_index = 0;
   arduboy.setCursor(0, 0);
   arduboy.print("Welcome to Ardubike!\n");
   arduboy.print("A: Level 1\n");
   arduboy.print("B: Infinte Mode!");
   if (arduboy.justPressed(A_BUTTON)) {
    gamestate = GAME_PLAY;
    mode = LEVEL_1;
   }
   if (arduboy.justPressed(B_BUTTON)) {
    gamestate = GAME_PLAY;
    arduboy.initRandomSeed();
    mode = LEVEL_INFINITE; 
   }
}

void game_play(int MODE) {
  arduboy.clear();

  // get the road moving
  scroll_road();

  // draw the rider and set him on the road
  arduboy.drawBitmap(4, SCREEN_HEIGHT - rider_height - 1 - lane_shift, rider_flat, 16, 16, WHITE);
  for (int j = 1; j <= 4; j++) {
    for (int i = -8; i < SCREEN_WIDTH + 8; i = i + 8) {
      arduboy.drawBitmap(i + scroll_offset, SCREEN_HEIGHT - j * 8, road_tile, 8, 8, WHITE); 
    }
  }

  //draw the map
  if (mode == LEVEL_1) {
    for (int i = 1; i <= TRACK_LENGTH; i++) {
      for (int j = 1; j <= LANE_COUNT; j++) {
        if (CURRENT_TRACK[i - 1][j - 1] == MUD) {
          draw_mapped_obstacle(MUD, i, j);
        }
      }
    }
  } else if ( mode == LEVEL_INFINITE) { 
    // Remove obstacles that have moved off screen
    for (int i = 0; i < MAX_NUM_OF_OBSTACLES; i++) {
      if (current_obstacles[i].obstacle_x < -1 - TRACK_ITEM_SIZE) {
        current_obstacles[i].isActive = false;
      }
    }
    // Check incactive and give them a chance to get made.
    for (int i = 0; i < MAX_NUM_OF_OBSTACLES; i++) {
      if (!current_obstacles[i].isActive and random(0, 50) == 1) {
        current_obstacles[i].isActive = true;
        current_obstacles[i].obstacle_type = MUD;
        current_obstacles[i].obstacle_lane = random(1, 5);
        current_obstacles[i].obstacle_x = 8 + SCREEN_WIDTH;
      }
    }
    for (int i = 0; i < MAX_NUM_OF_OBSTACLES; i++) {
      if (current_obstacles[i].isActive) {
        draw_random_obstacle(current_obstacles[i].obstacle_type, current_obstacles[i].obstacle_x, current_obstacles[i].obstacle_lane);
        current_obstacles[i].obstacle_x -= 1;
      }
    }
  }

  track_index += 1;
  
  if (arduboy.justPressed(UP_BUTTON)) {
    change_lanes(up);
  }
  
  if (arduboy.justPressed(DOWN_BUTTON)) {
    change_lanes(down);
  }

  if (arduboy.justPressed(B_BUTTON)) {
    gamestate = GAME_TITLE;
  }
}
