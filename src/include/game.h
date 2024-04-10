#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include <raylib.h>
#include "board.h"

#define WINDOWWIDTH 800 
#define WINDOWHEIGHT 800

// finds the correct tile size based on the
// window sizes listed above
#if WINDOWWIDTH < WINDOWHEIGHT
    #define TILESIZE (WINDOWWIDTH / 8)
#else
    #define TILESIZE (WINDOWHEIGHT / 8)
#endif

extern bool color;
extern bool isWhiteCheck;
extern bool isBlackCheck;

extern Tile checkBoard[8][8];

#endif //CHESS_GAME_H
