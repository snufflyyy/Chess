#include <raylib.h>

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

typedef enum {
    NONE,
    PAWN,
    BISHOP,
    KNIGHT,
    ROOK,
    QUEEN,
    KING
} PieceType;

typedef struct {
    char letter;
    short number;
    
    Rectangle rectangle;
    PieceType type;
    Texture2D texture;
    bool color;
    int moves;
} Piece;

void getVaildMoves(int x, int y, bool color);

void createPieces();

void drawPieces();

#endif //CHESS_PIECE_H
