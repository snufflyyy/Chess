#ifndef CHESS_INPUT_H
#define CHESS_INPUT_H

#include "board.h"
#include <raylib.h>

extern Vector2 selectedPiece;

extern Tile checkBoard[8][8];

void input();

#endif //CHESS_INPUT_H
