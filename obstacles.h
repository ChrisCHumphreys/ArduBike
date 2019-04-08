#ifndef OBSTACLES_H
#define OBSTACLES_H

const unsigned char PROGMEM low_long_jump[] = {
  0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0x10, 0x10, 0x8, 0x8, 0x4, 0x4, 0x2, 0x2, 0xff, 0x1, 0x1, 0xff, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf8, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1, 0x1, 0xfe, 0xff, 0xfd, 0xff, 0xfb, 0xff, 0xf7, 0xff, 0xef, 0xff, 0xdf, 0xff, 0xbf, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1, 0x1, 0xfe, 0xff, 0xfd, 0xff, 0xfb, 0xff, 0xf7, 0xff, 0xef, 0xff, 0xdf, 0xff, 0xbf, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1, 0x1, 0xfe, 0xff, 0xfd, 0xff, 0xfb, 0xff, 0xf7, 0xff, 0xef, 0xff, 0xdf, 0xff, 0xbf, 0xff, 0x7f, 0x80, 0x80, 0x40, 0x40, 0x20, 0x20, 0x10, 0x10, 0x8, 0x8, 0x4, 0x4, 0x2, 0x2, 0x1, 0x1, 0x1, 0x1, 0x3, 0x3, 0x7, 0x7, 0xf, 0xf, 0x1f, 0x1f, 0x3f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 
};

const unsigned char PROGMEM bump[] = {
  0x8, 0x8, 0x4, 0x4, 0x2, 0x2, 0xff, 0x1, 0x1, 0xff, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1, 0x1, 0xff, 0xff, 0xfd, 0xff, 0xfb, 0xff, 0xf7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1, 0x1, 0xff, 0xff, 0xfb, 0xff, 0xf7, 0xff, 0xef, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1, 0x1, 0xff, 0xff, 0xfb, 0xff, 0xf7, 0xff, 0xef, 0x8, 0x8, 0x4, 0x4, 0x2, 0x2, 0x1, 0x1, 0x1, 0x1, 0x3, 0x3, 0x7, 0x7, 0xf, 0xf,
};

const unsigned char PROGMEM tall_jump[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0xfe, 0x1, 0x1, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1, 0x1, 0xff, 0xfb, 0xff, 0xef, 0xff, 0xbf, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1, 0x1, 0xff, 0xfd, 0xff, 0xf7, 0xff, 0xdf, 0xff, 0x7e, 0xff, 0xfb, 0xff, 0xef, 0xff, 0xbf, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x1, 0x1, 0xff, 0xfd, 0xff, 0xf7, 0xff, 0xdf, 0xff, 0x7f, 0xff, 0xfd, 0xff, 0xf7, 0xff, 0xdf, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x3, 0x1, 0x1, 0x3, 0x7, 0xf, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xf7, 0xff, 0xdf, 0xff, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1, 0x3, 0x7, 0xf, 0x1f, 0x3f, 0x7f, 0xff,
};  
#endif
