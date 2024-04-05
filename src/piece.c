#include "include/piece.h"
#include "include/variables.h"
#include "include/board.h"

void createPieces() {
    Image whitePawn = LoadImage("../assets/pieces/white/pawn.png");
    Image whiteBishop = LoadImage("../assets/pieces/white/bishop.png");
    Image whiteKnight = LoadImage("../assets/pieces/white/knight.png");
    Image whiteRook = LoadImage("../assets/pieces/white/rook.png");
    Image whiteQueen = LoadImage("../assets/pieces/white/queen.png");
    Image whiteKing = LoadImage("../assets/pieces/white/king.png");

    Image blackPawn = LoadImage("../assets/pieces/black/pawn.png");
    Image blackBishop = LoadImage("../assets/pieces/black/bishop.png");
    Image blackKnight = LoadImage("../assets/pieces/black/knight.png");
    Image blackRook = LoadImage("../assets/pieces/black/rook.png");
    Image blackQueen = LoadImage("../assets/pieces/black/queen.png");
    Image blackKing = LoadImage("../assets/pieces/black/king.png");

    ImageResize(&whitePawn, TILESIZE, TILESIZE);
    ImageResize(&whiteBishop, TILESIZE, TILESIZE);
    ImageResize(&whiteKnight, TILESIZE, TILESIZE);
    ImageResize(&whiteRook, TILESIZE, TILESIZE);
    ImageResize(&whiteQueen, TILESIZE, TILESIZE);
    ImageResize(&whiteKing, TILESIZE, TILESIZE);

    ImageResize(&blackPawn, TILESIZE, TILESIZE);
    ImageResize(&blackBishop, TILESIZE, TILESIZE);
    ImageResize(&blackKnight, TILESIZE, TILESIZE);
    ImageResize(&blackRook, TILESIZE, TILESIZE);
    ImageResize(&blackQueen, TILESIZE, TILESIZE);
    ImageResize(&blackKing, TILESIZE, TILESIZE);

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            // white pawns
            if (chessBoard[x][y].number == 2) {
                chessBoard[x][y].piece.type = PAWN;
                chessBoard[x][y].piece.color = true;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(whitePawn);
            }

            // white rook
            if (chessBoard[x][y].letter == 'A' && chessBoard[x][y].number == 1) {
                chessBoard[x][y].piece.type = ROOK;
                chessBoard[x][y].piece.color = true;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteRook);
            }

            // black pawns
            if (chessBoard[x][y].number == 7) {
                chessBoard[x][y].piece.type = PAWN;
                chessBoard[x][y].piece.color = false;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(blackPawn);
            }

            // black rook
            if (chessBoard[x][y].letter == 'A' && chessBoard[x][y].number == 8) {
                chessBoard[x][y].piece.type = ROOK;
                chessBoard[x][y].piece.color = false;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(blackRook);
            }
        }
    }

    // clean up
    UnloadImage(whitePawn);
    UnloadImage(whiteBishop);
    UnloadImage(whiteKnight);
    UnloadImage(whiteRook);
    UnloadImage(whiteQueen);
    UnloadImage(whiteKing);

    UnloadImage(blackPawn);
    UnloadImage(blackBishop);
    UnloadImage(blackKnight);
    UnloadImage(blackRook);
    UnloadImage(blackQueen);
    UnloadImage(blackKing);
}

void drawPieces() {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (chessBoard[x][y].piece.type != NONE) {
                DrawTexture(
                    chessBoard[x][y].piece.texture,
                    chessBoard[x][y].piece.rectangle.x,
                    chessBoard[x][y].piece.rectangle.y,
                    WHITE
                );
            }
        }
    }
}