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
void getValidMoves(int x, int y);
bool isValidMove(int x, int y, int x2, int y2);
void drawPieces();
void cleanUpPieces();

#endif
