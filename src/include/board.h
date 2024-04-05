#include <raylib.h>
#include "piece.h"

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

typedef struct {
    // a, b, c, d, e, f, g, h
    char letter;
    // 1, 2, 3, 4, 5, 6, 7, 8
    short number;

    Piece piece;
    Rectangle rectangle;
    Color color;
} Tile;

extern Tile chessBoard[8][8];

void createBoard(bool color);

void drawBoard();

void boardCleanUp();

#endif //CHESS_BOARD_H
