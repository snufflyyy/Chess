#ifndef CHESS_PIECES_H
#define CHESS_PIECES_H

#include <raylib.h>

extern Image windowIconWhite;
extern Image windowIconBlack;

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

void loadPieceImages();
void createPieces();
void resizePieces();

void drawPieces();
void cleanUpPieces();

#endif
