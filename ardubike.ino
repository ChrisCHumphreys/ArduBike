// Chris Humphreys
// April 05, 2019
// Ardubike Game

#include <Arduboy2.h>
#include "sprites.h"
#include "tracks.h"

Arduboy2 arduboy;

const int SCREEN_HEIGHT = 64;
const int SCREEN_WIDTH = 128;
const int rider_height = 16;
int lane_shift = 0;
int up = 1;
int down = -1;
int scroll_offset = 0;
int rand_0_4 = 0;
int num_of_puddles = 0;


void change_lanes(int);
void scroll_road();
bool isMud();

void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.setFrameRate(60);
  // TODO: use initRandomSeed after user presses a button
  arduboy.initRandomSeed();
  rand_0_4 = random(5);
  arduboy.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!(arduboy.nextFrame())) return;
  scroll_road();
  arduboy.pollButtons();
  arduboy.clear();
  arduboy.print("Welcome to Ardubike!");
  arduboy.setCursor(0, 8);
  arduboy.drawBitmap(4, SCREEN_HEIGHT - rider_height - 1 - lane_shift, rider_flat, 16, 16, WHITE);
  for (int j = 1; j <= 4; j++) {
    for (int i = -8; i < SCREEN_WIDTH + 8; i = i + 8) {
      arduboy.drawBitmap(i + scroll_offset, SCREEN_HEIGHT - j * 8, road_tile, 8, 8, WHITE); 
    }
  }
  
  if (isMud() and num_of_puddles < 4) {
    arduboy.drawBitmap(32, SCREEN_HEIGHT - rand_0_4 * 8, mud_tile, 8, 8, WHITE);
    num_of_puddles += 1;
  }
  if (arduboy.justPressed(UP_BUTTON)) {
    change_lanes(up);
  }
  if (arduboy.justPressed(DOWN_BUTTON)) {
    change_lanes(down);
  }

  
  rand_0_4 = random(5);
  
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
  if (scroll_offset == -7) {
    scroll_offset = 0;
  }
}

bool isMud() {
    int new_rand = random(5);
    if (new_rand == 0) {
      return true;
    }
    return false;
}
