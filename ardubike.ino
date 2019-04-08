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
#define LEVEL_1         1
#define CURRENT_TRACK   track1

/**
 * Constants
 */
const int SCREEN_HEIGHT = 64;
const int SCREEN_WIDTH = 128;
const int RIDER_HEIGHT = 16;
const int MAX_NUM_OF_OBSTACLES = 6;

/**
 * Represents an obstacle on the map
 */
struct random_obstacle {
  int obstacle_type;
  int obstacle_lane;
  int obstacle_x;
  bool isActive;
};

int lane_shift = 0;
int up = 1;
int down = -1;
int scroll_offset = 0; /**< Offset starts at 0 and increases by 1 on each Frame */
int track_index = 0;
int gamestate = GAME_TITLE;
int mode = LEVEL_1;
int obstacle_count = 0;
bool wheelie = false; 
int frame = 0;
int blocked_drawing_counter = 0;

random_obstacle current_obstacles[MAX_NUM_OF_OBSTACLES];
Arduboy2 arduboy;

void change_lanes(int);
//void scroll_road();
void draw_mapped_obstacle(int obstacle, int index_offset, int lane);
void draw_random_obstacle(int obstacle, int x, int lane);
void title_screen();
void game_play(int mode);

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
      game_play(mode);
      break;
  }
  
  arduboy.display();
}

void change_lanes(int direction) {
  // shift down a lane
  if (direction < 0 and lane_shift > 0) {
    lane_shift -= 8;
  }
  // shift up a lane
  if (direction > 0 and lane_shift < 24) {
    lane_shift += 8;
  }
}

//void scroll_road() {
//  // Uses values between 0 and -8 becuase the road tile is exacly 8 pixels wide
//  scroll_offset = scroll_offset - 1;
//  if (scroll_offset == -8) {
//    scroll_offset = 0;
//  }
//}

void draw_mapped_obstacle(int obstacle, int index_offset, int lane) {
  int this_item_size;
  unsigned char* this_obstacle;
  if (obstacle == CLEAR) {
    this_obstacle = road_tile;
    this_item_size = TRACK_ITEM_SIZE;
    // slightly different from draw_random_obstacle as we have to track ithe index to move through our map
    arduboy.drawBitmap((index_offset * TRACK_ITEM_SIZE) - track_index, 
                       SCREEN_HEIGHT - ((lane + 1) * TRACK_ITEM_SIZE), this_obstacle, TRACK_ITEM_SIZE, 
                       TRACK_ITEM_SIZE, 
                       WHITE);
  }
  if (obstacle == MUD) {
    this_obstacle = mud_tile;
    this_item_size = TRACK_ITEM_SIZE;
    // slightly different from draw_random_obstacle as we have to track ithe index to move through our map
    arduboy.drawBitmap((index_offset * TRACK_ITEM_SIZE) - track_index, 
                       SCREEN_HEIGHT - ((lane + 1) * TRACK_ITEM_SIZE), this_obstacle, TRACK_ITEM_SIZE, 
                       TRACK_ITEM_SIZE, 
                       WHITE);
  }
  if (obstacle == LLJ) {
    this_obstacle = low_long_jump;
    //is_low_rising = true;
    // paint the area behind the jump black first
    arduboy.fillRect((index_offset * TRACK_ITEM_SIZE) - track_index,
                     SCREEN_HEIGHT - (40), 32, 40, INVERT);
    arduboy.drawBitmap((index_offset * TRACK_ITEM_SIZE) - track_index, 
                       SCREEN_HEIGHT - (40), this_obstacle, 32, 
                       40, 
                       WHITE);
  }
  if (obstacle == BUMP) {
    this_obstacle = bump;
    arduboy.fillRect((index_offset * TRACK_ITEM_SIZE) - track_index,
                     SCREEN_HEIGHT - (36), 16, 36, INVERT);
    arduboy.drawBitmap((index_offset * TRACK_ITEM_SIZE) - track_index, 
                       SCREEN_HEIGHT - (36), this_obstacle, 16, 
                       36, 
                       WHITE);
  }
  if (obstacle == TALL) {
    this_obstacle = tall_jump;
    arduboy.fillRect((index_offset * TRACK_ITEM_SIZE) - track_index,
                     SCREEN_HEIGHT - (48), 32, 48, INVERT);
    arduboy.drawBitmap((index_offset * TRACK_ITEM_SIZE) - track_index, 
                       SCREEN_HEIGHT - (48), this_obstacle, 32, 
                       48, 
                       WHITE);
  }
  

}

void draw_random_obstacle(int obstacle, int x, int lane) {
  // in random mode we just write to the x value given, without the even spacing used above.
  // because of this we do see overlapping in the random version.
  arduboy.drawBitmap(x, 
                     SCREEN_HEIGHT - (lane * TRACK_ITEM_SIZE), 
                     mud_tile, TRACK_ITEM_SIZE, TRACK_ITEM_SIZE, 
                     WHITE);
}

void title_screen() {
   arduboy.clear();
   track_index = 0;   /**< Set index to 0, indicating start of the map */

   // Draw Menu
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

  // Draw the road
//  for (int j = 1; j <= 4; j++) {
//    for (int i = -8; i < SCREEN_WIDTH + 8; i = i + 8) {
//      arduboy.drawBitmap(i + scroll_offset, SCREEN_HEIGHT - j * 8, road_tile, 8, 8, WHITE); 
//    }
//  }
  
  // get the road moving
  //scroll_road();

  //draw the map using map in tracks.h
  if (mode == LEVEL_1 and blocked_drawing_counter == 0) {
    for (int i = 0; i < TRACK_LENGTH; i++) {
      for (int j = 0; j < LANE_COUNT; j++) {
        if (CURRENT_TRACK[i][j] == MUD) {
          draw_mapped_obstacle(MUD, i, j);
        }
        if (CURRENT_TRACK[i][j] == LLJ) {
          draw_mapped_obstacle(LLJ, i, j);
        }
        if (CURRENT_TRACK[i][j] == BUMP) {
          draw_mapped_obstacle(BUMP, i, j);
        }
        if (CURRENT_TRACK[i][j] == TALL) {
          draw_mapped_obstacle(TALL, i, j);
        }
        if (CURRENT_TRACK[i][j] == CLEAR) {
          draw_mapped_obstacle(CLEAR, i, j);
          //arduboy.drawBitmap(i + scroll_offset, SCREEN_HEIGHT - j * 8, road_tile, 8, 8, WHITE);
        }
      }
    } 
  // Draw the map using random obstacles
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
    // wrtie the updated obstacles to the screen and adust x to make them move
    for (int i = 0; i < MAX_NUM_OF_OBSTACLES; i++) {
      if (current_obstacles[i].isActive) {
        draw_random_obstacle(current_obstacles[i].obstacle_type, 
                             current_obstacles[i].obstacle_x, 
                             current_obstacles[i].obstacle_lane);
        current_obstacles[i].obstacle_x -= 1;
      }
    }
  }
  if (blocked_drawing_counter != 0) {
      blocked_drawing_counter -= 1;
  }

  // draw the rider
  
  arduboy.drawBitmap(4, SCREEN_HEIGHT - RIDER_HEIGHT - 1 - lane_shift, rider_low_incline[frame / 4], 16, 16, WHITE); 
    
  
  // for animation testing
  if (wheelie == true) {
    if (frame < 15) {
      frame += 1;
    } else {
       frame = 15;
    }
  }
  // Track index is like an index in an array the we are moving through as we play the game.
  track_index += 1;
  
  if (arduboy.justPressed(UP_BUTTON)) {
    change_lanes(up);
  }
  
  if (arduboy.justPressed(DOWN_BUTTON)) {
    change_lanes(down);
  }

  // Right now I am using B as a universal exit mode.
  if (arduboy.justPressed(B_BUTTON)) {
    gamestate = GAME_TITLE;
  }

  // Just to test animations
  if (arduboy.pressed(A_BUTTON) and gamestate == GAME_PLAY) {
    wheelie = true;
  } else {
    wheelie = false;
    frame = 0;
  }
}
