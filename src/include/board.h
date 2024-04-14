#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <stdbool.h>
#include <raylib.h>

#include "game.h"
#include "pieces.h"

typedef struct Tile {
    char letter;
    int number;
    bool isValid;
    Rectangle rectangle;
    Color color;
    Piece piece;
} Tile;

extern Tile chessBoard[BOARDSIZE][BOARDSIZE];
extern bool checkBoard[BOARDSIZE][BOARDSIZE];

void createBoard();
void rotateBoard();

void drawBoard();
void drawLetters();
void drawNumbers();

#endif
