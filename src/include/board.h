#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <raylib.h>
#include "piece.h"

typedef struct {
    bool isVaild;
    Piece piece;
    Rectangle rectangle;
    Color color;
} Tile;

extern Tile chessBoard[8][8];
extern Tile checkBoard[8][8];

void createBoard();
void checkForCheck();
void rotateBoard();
void drawBoard();

#endif //CHESS_BOARD_H
