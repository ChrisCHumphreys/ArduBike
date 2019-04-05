#ifndef TRACKS_H
#define TRACKS_H

#define CLEAR           0
#define MUD             1
#define TRACK_LENGTH     5
#define LANE_COUNT      4 


const int track1[TRACK_LENGTH][LANE_COUNT] = {
  {MUD,   CLEAR,  CLEAR,  CLEAR},
  {CLEAR, CLEAR,  CLEAR,  CLEAR},
  {CLEAR, MUD,    MUD,    CLEAR},
  {CLEAR, CLEAR,  MUD,    CLEAR},
  {MUD,   MUD,    MUD,    CLEAR},
};

#endif
