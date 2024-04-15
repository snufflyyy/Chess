#include "include/pieces.h"
#include "include/game.h"
#include "include/board.h"

Image whitePawn;
Image whiteBishop;
Image whiteKnight;
Image whiteRook;
Image whiteQueen;
Image whiteKing;

Image blackPawn;
Image blackBishop;
Image blackKnight;
Image blackRook;
Image blackQueen;
Image blackKing;

void loadPieceImages() {
    whitePawn = LoadImage("../assets/pieces/white/pawn.png");
    whiteBishop = LoadImage("../assets/pieces/white/bishop.png");
    whiteKnight = LoadImage("../assets/pieces/white/knight.png");
    whiteRook = LoadImage("../assets/pieces/white/rook.png");
    whiteQueen = LoadImage("../assets/pieces/white/queen.png");
    whiteKing = LoadImage("../assets/pieces/white/king.png");

    blackPawn = LoadImage("../assets/pieces/black/pawn.png");
    blackBishop = LoadImage("../assets/pieces/black/bishop.png");
    blackKnight = LoadImage("../assets/pieces/black/knight.png");
    blackRook = LoadImage("../assets/pieces/black/rook.png");
    blackQueen = LoadImage("../assets/pieces/black/queen.png");
    blackKing = LoadImage("../assets/pieces/black/king.png");
}

void resizePieceImages() {
    ImageResize(&whitePawn, tileScale, tileScale);
    ImageResize(&whiteBishop, tileScale, tileScale);
    ImageResize(&whiteKnight, tileScale, tileScale);
    ImageResize(&whiteRook, tileScale, tileScale);
    ImageResize(&whiteQueen, tileScale, tileScale);
    ImageResize(&whiteKing, tileScale, tileScale);

    ImageResize(&blackPawn, tileScale, tileScale);
    ImageResize(&blackBishop, tileScale, tileScale);
    ImageResize(&blackKnight, tileScale, tileScale);
    ImageResize(&blackRook, tileScale, tileScale);
    ImageResize(&blackQueen, tileScale, tileScale);
    ImageResize(&blackKing, tileScale, tileScale);
}

void createPieces() {
    loadPieceImages();
    resizePieceImages();

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            // white pawn
            if (chessBoard[x][y].number == 2) {
                chessBoard[x][y].piece.type = PAWN;
                chessBoard[x][y].piece.color = true;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(whitePawn);
            }

            if (chessBoard[x][y].number == 1) {
                // white rooks
                if (chessBoard[x][y].letter == 'A') { // left
                    chessBoard[x][y].piece.type = ROOK;
                    chessBoard[x][y].piece.color = true;
                    chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteRook);
                }

                if (chessBoard[x][y].letter == 'H') { // right
                    chessBoard[x][y].piece.type = ROOK;
                    chessBoard[x][y].piece.color = true;
                    chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteRook);
                }

                // white knights
                if (chessBoard[x][y].letter == 'B') { // left
                    chessBoard[x][y].piece.type = KNIGHT;
                    chessBoard[x][y].piece.color = true;
                    chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteKnight);
                }

                if (chessBoard[x][y].letter == 'G') { // right
                    chessBoard[x][y].piece.type = KNIGHT;
                    chessBoard[x][y].piece.color = true;
                    chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteKnight);
                }

                // white bishop
                if (chessBoard[x][y].letter == 'C') { // left
                    chessBoard[x][y].piece.type = BISHOP;
                    chessBoard[x][y].piece.color = true;
                    chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteBishop);
                }

                if (chessBoard[x][y].letter == 'F') { // right
                    chessBoard[x][y].piece.type = BISHOP;
                    chessBoard[x][y].piece.color = true;
                    chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteBishop);
                }

                // white queen
                if (chessBoard[x][y].letter == 'D') {
                    chessBoard[x][y].piece.type = QUEEN;
                    chessBoard[x][y].piece.color = true;
                    chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteQueen);
                }

                // white king
                if (chessBoard[x][y].letter == 'E') {
                    chessBoard[x][y].piece.type = KING;
                    chessBoard[x][y].piece.color = true;
                    chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteKing);
                }
            }

            // black pawns
            if (chessBoard[x][y].number == 7) {
                chessBoard[x][y].piece.type = PAWN;
                chessBoard[x][y].piece.color = false;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(blackPawn);
            }

            if (chessBoard[x][y].number == 8) {
                // black rooks
                if (chessBoard[x][y].letter == 'A') { // left
                    chessBoard[x][y].piece.type = ROOK;
                    chessBoard[x][y].piece.color = false;
                    chessBoard[x][y].piece.texture = LoadTextureFromImage(blackRook);
                }

                if (chessBoard[x][y].letter == 'H') { // right
                    chessBoard[x][y].piece.type = ROOK;
                    chessBoard[x][y].piece.color = false;
                    chessBoard[x][y].piece.texture = LoadTextureFromImage(blackRook);
                }

                // black knights
                if (chessBoard[x][y].letter == 'B') { // left
                    chessBoard[x][y].piece.type = KNIGHT;
                    chessBoard[x][y].piece.color = false;
                    chessBoard[x][y].piece.texture = LoadTextureFromImage(blackKnight);
                }

                if (chessBoard[x][y].letter == 'G') { // right
                    chessBoard[x][y].piece.type = KNIGHT;
                    chessBoard[x][y].piece.color = false;
                    chessBoard[x][y].piece.texture = LoadTextureFromImage(blackKnight);
                }

                // black bishop
                if (chessBoard[x][y].letter == 'C') { // left
                    chessBoard[x][y].piece.type = BISHOP;
                    chessBoard[x][y].piece.color = false;
                    chessBoard[x][y].piece.texture = LoadTextureFromImage(blackBishop);
                }

                if (chessBoard[x][y].letter == 'F') { // right
                    chessBoard[x][y].piece.type = BISHOP;
                    chessBoard[x][y].piece.color = false;
                    chessBoard[x][y].piece.texture = LoadTextureFromImage(blackBishop);
                }

                // black queen
                if (chessBoard[x][y].letter == 'D') {
                    chessBoard[x][y].piece.type = QUEEN;
                    chessBoard[x][y].piece.color = false;
                    chessBoard[x][y].piece.texture = LoadTextureFromImage(blackQueen);
                }

                // black king
                if (chessBoard[x][y].letter == 'E') {
                    chessBoard[x][y].piece.type = KING;
                    chessBoard[x][y].piece.color = false;
                    chessBoard[x][y].piece.texture = LoadTextureFromImage(blackKing);
                }
            }
        }
    }
}

void resizePieces() {
    cleanUpPieces();
    loadPieceImages();
    resizePieceImages();

    for (int x = 0; x < BOARDSIZE; x++) {
        for (int y = 0; y < BOARDSIZE; y++) {
            chessBoard[x][y].piece.rectangle = chessBoard[x][y].rectangle;

            UnloadTexture(chessBoard[x][y].piece.texture);

            if (chessBoard[x][y].piece.color == true) { // white
                switch (chessBoard[x][y].piece.type) {
                    case NONE: /** do nothing **/ break;
                    case PAWN: chessBoard[x][y].piece.texture = LoadTextureFromImage(whitePawn); break;
                    case BISHOP: chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteBishop); break;
                    case KNIGHT: chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteKnight); break;
                    case ROOK: chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteRook); break;
                    case QUEEN: chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteQueen); break;
                    case KING: chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteKing); break;
                }
            } else { // black
                switch (chessBoard[x][y].piece.type) {
                    case NONE: /** do nothing **/ break;
                    case PAWN: chessBoard[x][y].piece.texture = LoadTextureFromImage(blackPawn); break;
                    case BISHOP: chessBoard[x][y].piece.texture = LoadTextureFromImage(blackBishop); break;
                    case KNIGHT: chessBoard[x][y].piece.texture = LoadTextureFromImage(blackKnight); break;
                    case ROOK: chessBoard[x][y].piece.texture = LoadTextureFromImage(blackRook); break;
                    case QUEEN: chessBoard[x][y].piece.texture = LoadTextureFromImage(blackQueen); break;
                    case KING: chessBoard[x][y].piece.texture = LoadTextureFromImage(blackKing); break;
                }
            }
        }
    }
}

void drawPieces() {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if ((chessBoard[x][y].piece.type != NONE) && (x != ((int) selectedPiece.x) || y != ((int) selectedPiece.y))) {
                DrawTexture (
                    chessBoard[x][y].piece.texture,
                    chessBoard[x][y].piece.rectangle.x,
                    chessBoard[x][y].piece.rectangle.y,
                    WHITE
                );
            }
        }
    }

    // this is used to make the selected piece render above the other pieces
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if ((chessBoard[x][y].piece.type != NONE) && x == ((int) selectedPiece.x) && y == ((int) selectedPiece.y)) {
                DrawTexture (
                    chessBoard[x][y].piece.texture,
                    chessBoard[x][y].piece.rectangle.x,
                    chessBoard[x][y].piece.rectangle.y,
                    WHITE
                );
            }
        }
    }
}

void cleanUpPieces() {
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

    for (int x = 0; x < BOARDSIZE; x++) {
        for (int y = 0; y < BOARDSIZE; y++) {
            UnloadTexture(chessBoard[x][y].piece.texture);
        }
    }
}