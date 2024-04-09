#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <raylib.h>

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
    Texture2D texture;
    PieceType type;
    bool color;
    int moves;
    bool canEnPassant;
} Piece;

void getVaildMoves(int x, int y);
void createPieces();
void drawPieces();
void pieceCleanUp();

#endif //CHESS_PIECE_H
