#include <raylib.h>
#include "piece.h"

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

typedef struct {
    char letter;
    short number;
    bool isVaild;
    Piece piece;
    Rectangle rectangle;
    Color color;
} Tile;

extern Tile chessBoard[8][8];

void createBoard();

void rotateBoard();

void drawBoard();

void boardCleanUp();

#endif //CHESS_BOARD_H
