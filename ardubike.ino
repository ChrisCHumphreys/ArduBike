// Chris Humphreys
// April 05, 2019
// Ardubike Game

#include <Arduboy2.h>
Arduboy2 arduboy;

void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  arduboy.clear();
  arduboy.print("Welcome to ardubike");
  arduboy.display();
}
