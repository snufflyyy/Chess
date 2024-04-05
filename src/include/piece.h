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
    Rectangle rectangle;
    PieceType type;
    Texture2D texture;
    bool color;
} Piece;

void createPieces();

void drawPieces();

#endif //CHESS_PIECE_H
