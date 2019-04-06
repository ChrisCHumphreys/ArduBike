#ifndef TRACKS_H
#define TRACKS_H

// These constants allow us to make human readable
// tracks.  They do take up a lot of space though.
#define CLEAR           0
#define MUD             1
#define LLJ             2  
#define TRACK_LENGTH    30
#define LANE_COUNT      4
#define TRACK_ITEM_SIZE 8

// Because Low long jump takes up 4 track widths, it must be 
// put into the first spot of array followed by 3 Clear blocks.


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
  {LLJ,   CLEAR,  CLEAR,  CLEAR},
};

#endif
