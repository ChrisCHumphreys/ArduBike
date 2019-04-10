#ifndef SPRITES_H
#define SPRITES_H

const unsigned char PROGMEM ardurider[] =
{
// width, height,
16, 16,
// FRAME 00
0x00, 0x00, 0x00, 0x00, 0x00, 0xb0, 0xf8, 0xf8, 0x90, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x78, 0xcc, 0xb4, 0xcc, 0x7f, 0x27, 0x7f, 0x7c, 0x4c, 0x7d, 0xcf, 0xb4, 0xcc, 0x78, 0x00, 
// FRAME 01
0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xfc, 0xfc, 0x88, 0x40, 0xc0, 0xc0, 0x40, 0xc0, 0x80, 0x00, 
0x00, 0x78, 0xcc, 0xb4, 0xcc, 0x78, 0x1f, 0x1f, 0x17, 0x02, 0x07, 0x0c, 0x0b, 0x0c, 0x07, 0x00, 
// FRAME 02
0x00, 0x00, 0x00, 0x00, 0xe8, 0xfc, 0xfc, 0x48, 0xf0, 0x50, 0x78, 0xcc, 0xb4, 0xcc, 0x78, 0x00, 
0x00, 0x78, 0xcc, 0xb4, 0xcc, 0x7f, 0x0f, 0x07, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const unsigned char PROGMEM ardurider_mask[] =
{
// width, height,
16, 16,
// FRAME 00
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// FRAME 01
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
// FRAME 02
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};

const unsigned char PROGMEM ardurider_plus_mask[] =
{
// width, height,
16, 16,
// FRAME 00
0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0xb0, 0xff, 0xf8, 0xff, 0xf8, 0xff, 
0x90, 0xff, 0x80, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 
0x00, 0xff, 0x78, 0xff, 0xcc, 0xff, 0xb4, 0xff, 0xcc, 0xff, 0x7f, 0xff, 0x27, 0xff, 0x7f, 0xff, 
0x7c, 0xff, 0x4c, 0xff, 0x7d, 0xff, 0xcf, 0xff, 0xb4, 0xff, 0xcc, 0xff, 0x78, 0xff, 0x00, 0xff, 

// FRAME 01
0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x38, 0xff, 0xfc, 0xff, 0xfc, 0xff, 
0x88, 0xff, 0x40, 0xff, 0xc0, 0xff, 0xc0, 0xff, 0x40, 0xff, 0xc0, 0xff, 0x80, 0xff, 0x00, 0xff, 
0x00, 0xff, 0x78, 0xff, 0xcc, 0xff, 0xb4, 0xff, 0xcc, 0xff, 0x78, 0xff, 0x1f, 0xff, 0x1f, 0xff, 
0x17, 0xff, 0x02, 0xff, 0x07, 0xff, 0x0c, 0xff, 0x0b, 0xff, 0x0c, 0xff, 0x07, 0xff, 0x00, 0xff, 

// FRAME 02
0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0xe8, 0xff, 0xfc, 0xff, 0xfc, 0xff, 0x48, 0xff, 
0xf0, 0xff, 0x50, 0xff, 0x78, 0xff, 0xcc, 0xff, 0xb4, 0xff, 0xcc, 0xff, 0x78, 0xff, 0x00, 0xff, 
0x00, 0xff, 0x78, 0xff, 0xcc, 0xff, 0xb4, 0xff, 0xcc, 0xff, 0x7f, 0xff, 0x0f, 0xff, 0x07, 0xff, 
0x05, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff,
};

#endif
