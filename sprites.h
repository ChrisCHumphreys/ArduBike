#ifndef SPRITES_H
#define SPRITES_H

const unsigned char PROGMEM rider_flat[] =
{
  // 16 X 16
  0x00, 0x00, 0x00, 0x00, 0x00, 0xb0, 0xf8, 0xf8, 0x90, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xcc, 0xb4, 0xcc, 0x7f, 0x37, 0x7f, 0x7f, 0x54, 0x3d, 0xcf, 0xb4, 0xcc, 0x78, 0x00, 
};

const unsigned char PROGMEM rider_low_incline[][32] = {
  {0x00, 0x00, 0x00, 0x00, 0x00, 0xb0, 0xf8, 0xf8, 0x90, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xcc, 0xb4, 0xcc, 0x7f, 0x37, 0x7f, 0x7f, 0x54, 0x3d, 0xcf, 0xb4, 0xcc, 0x78, 0x00, },
  {0x00, 0x00, 0x00, 0x00, 0x00, 0xb0, 0xf8, 0xf8, 0x90, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xcc, 0xb4, 0xcc, 0x7f, 0x37, 0x7f, 0x7f, 0x54, 0x3d, 0x67, 0x5a, 0x66, 0x3c, 0x00, },
  {0x00, 0x00, 0x00, 0x00, 0x18, 0xfc, 0xfc, 0xc8, 0x40, 0x40, 0x40, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x78, 0xcc, 0xb4, 0xcc, 0x7f, 0x27, 0x1f, 0x37, 0x1c, 0xf, 0x19, 0x16, 0x19, 0xf, 0x00, },
  {0x00, 0x00, 0x00, 0x00, 0x8, 0xfe, 0xfe, 0xe4, 0x40, 0x20, 0xc0, 0x60, 0xa0, 0x60, 0xc0, 0x00, 0x00, 0x3c, 0x66, 0x5a, 0x66, 0x3f, 0x13, 0xf, 0xb, 0xe, 0x3, 0x6, 0x5, 0x6, 0x3, 0x00, },
};

const unsigned char PROGMEM road_tile[] = 
{
  // 8 X 8
  0x1, 0x1, 0x00, 0x1, 0x1, 0x00, 0x1, 0x00, 
};

const unsigned char PROGMEM mud_tile[] = 
{
  // 8 X 8  
  0x18, 0x24, 0x6a, 0x34, 0x66, 0x28, 0x54, 0x34, 
};

#endif
