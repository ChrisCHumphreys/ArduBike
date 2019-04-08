#ifndef TRACKS_H
#define TRACKS_H

// These constants allow us to make human readable
// tracks.  They do take up a lot of space though.
#define CLEAR           0
#define MUD             1
#define LLJ             2  
#define BUMP            3
#define TALL            4
#define GRASS           5

#define TRACK_LENGTH    47
#define LANE_COUNT      4
#define TRACK_ITEM_SIZE 8

// Because Low long jump takes up 4 track widths, it must be 
// put into the first spot of array followed by 3 grass blocks.
// must then be followed by 3 {GRASS, GRASS,  GRASS,  GRASS},'s

// Because Bum takes 2 track widths it must be put into first spot,
// with the other spots grass.
// must then be followed by 2 {GRASS, GRASS,  GRASS,  GRASS},'s


const int track1[TRACK_LENGTH][LANE_COUNT] = {
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, MUD,    CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, MUD,    CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {MUD,   CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  MUD,    CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, MUD,    CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  MUD  },
  {LLJ,   GRASS,  GRASS,  GRASS},
  {GRASS, GRASS,  GRASS,  GRASS},
  {GRASS, GRASS,  GRASS,  GRASS},
  {GRASS, GRASS,  GRASS,  GRASS},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  MUD,    CLEAR},
  {BUMP,  GRASS,  GRASS,  GRASS},
  {GRASS, GRASS,  GRASS,  GRASS},
  {CLEAR, CLEAR,  CLEAR,  CLEAR}, 
  {BUMP,  GRASS,  GRASS,  GRASS},
  {GRASS, GRASS,  GRASS,  GRASS},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {TALL,  GRASS,  GRASS,  GRASS},
  {GRASS, GRASS,  GRASS,  GRASS},
  {GRASS, GRASS,  GRASS,  GRASS},
  {GRASS, GRASS,  GRASS,  GRASS},
  {CLEAR, MUD,    CLEAR,  CLEAR},  
};

#endif
