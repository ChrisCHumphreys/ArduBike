// Chris Humphreys
// April 05, 2019
// Ardubike Game

#include <Arduboy2.h>
Arduboy2 arduboy;

const unsigned char PROGMEM ardurider[] =
{
// width, height,
0x00, 0x00, 0x00, 0x00, 0x00, 0xb0, 0xf8, 0xf8, 0x90, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xcc, 0xb4, 0xcc, 0x7f, 0x37, 0x7f, 0x7f, 0x74, 0x7d, 0xcf, 0xb4, 0xcc, 0x78, 0x00, 
};

void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  arduboy.clear();
  arduboy.print("Welcome to ardubike");
  arduboy.drawBitmap(20, 20, ardurider, 16, 16, WHITE);
  arduboy.display();
}
