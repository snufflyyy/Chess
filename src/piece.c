#include "include/piece.h"
#include "include/variables.h"
#include "include/board.h"
#include "include/input.h"

#include <stdio.h>

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

    // white will always be first, thats why these values are hard coded

    // white pawn
    for (int x = 0; x < 8; x++) {
        chessBoard[x][6].piece.type = PAWN;
        chessBoard[x][6].piece.color = true;
        chessBoard[x][6].piece.texture = LoadTextureFromImage(whitePawn);
    }

    // white rooks

    // left
    chessBoard[0][7].piece.type = ROOK;
    chessBoard[0][7].piece.color = true;
    chessBoard[0][7].piece.texture = LoadTextureFromImage(whiteRook);

    // right
    chessBoard[7][7].piece.type = ROOK;
    chessBoard[7][7].piece.color = true;
    chessBoard[7][7].piece.texture = LoadTextureFromImage(whiteRook);

    // white knights

    // left
    chessBoard[1][7].piece.type = KNIGHT;
    chessBoard[1][7].piece.color = true;
    chessBoard[1][7].piece.texture = LoadTextureFromImage(whiteKnight);

    // right
    chessBoard[6][7].piece.type = KNIGHT;
    chessBoard[6][7].piece.color = true;
    chessBoard[6][7].piece.texture = LoadTextureFromImage(whiteKnight);

    // white bishops

    // left
    chessBoard[2][7].piece.type = BISHOP;
    chessBoard[2][7].piece.color = true;
    chessBoard[2][7].piece.texture = LoadTextureFromImage(whiteBishop);

    // right
    chessBoard[5][7].piece.type = BISHOP;
    chessBoard[5][7].piece.color = true;
    chessBoard[5][7].piece.texture = LoadTextureFromImage(whiteBishop);

    // white queen
    chessBoard[3][7].piece.type = QUEEN;
    chessBoard[3][7].piece.color = true;
    chessBoard[3][7].piece.texture = LoadTextureFromImage(whiteQueen);

    // white king
    chessBoard[4][7].piece.type = KING;
    chessBoard[4][7].piece.color = true;
    chessBoard[4][7].piece.texture = LoadTextureFromImage(whiteKing);

    // black pieces

    // black pawn
    for (int x = 0; x < 8; x++) {
        chessBoard[x][1].piece.type = PAWN;
        chessBoard[x][1].piece.color = false;
        chessBoard[x][1].piece.texture = LoadTextureFromImage(blackPawn);
    }

    // black rooks

    // left
    chessBoard[0][0].piece.type = ROOK;
    chessBoard[0][0].piece.color = false;
    chessBoard[0][0].piece.texture = LoadTextureFromImage(blackRook);

    // right
    chessBoard[7][0].piece.type = ROOK;
    chessBoard[7][0].piece.color = false;
    chessBoard[7][0].piece.texture = LoadTextureFromImage(blackRook);

    // black knights

    // left
    chessBoard[1][0].piece.type = KNIGHT;
    chessBoard[1][0].piece.color = false;
    chessBoard[1][0].piece.texture = LoadTextureFromImage(blackKnight);

    // right
    chessBoard[6][0].piece.type = KNIGHT;
    chessBoard[6][0].piece.color = false;
    chessBoard[6][0].piece.texture = LoadTextureFromImage(blackKnight);

    // black bishops

    // left
    chessBoard[2][0].piece.type = BISHOP;
    chessBoard[2][0].piece.color = false;
    chessBoard[2][0].piece.texture = LoadTextureFromImage(blackBishop);

    // right
    chessBoard[5][0].piece.type = BISHOP;
    chessBoard[5][0].piece.color = false;
    chessBoard[5][0].piece.texture = LoadTextureFromImage(blackBishop);

    // white queen
    chessBoard[3][0].piece.type = QUEEN;
    chessBoard[3][0].piece.color = false;
    chessBoard[3][0].piece.texture = LoadTextureFromImage(blackQueen);

    // white king
    chessBoard[4][0].piece.type = KING;
    chessBoard[4][0].piece.color = false;
    chessBoard[4][0].piece.texture = LoadTextureFromImage(blackKing);

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

void getVaildMoves(int x, int y) {
    switch (chessBoard[x][y].piece.type) {
        case NONE: /** do nothing :) **/ break;
        case PAWN:
            // normal moves

            // first move
            if (chessBoard[x][y].piece.moves == 0) {
                chessBoard[x][y - 1].isVaild = true;
                chessBoard[x][y - 2].isVaild = true;
            } else if (chessBoard[x][y - 1].piece.type == NONE) { // after first move
                chessBoard[x][y - 1].isVaild = true;
            }
            
            // capture

            // right
            if (chessBoard[x + 1][y - 1].piece.color != color && chessBoard[x + 1][y - 1].piece.type != NONE) {
                chessBoard[x + 1][y - 1].isVaild = true;
            }
            // left
            if (chessBoard[x - 1][y - 1].piece.color != color && chessBoard[x - 1][y - 1].piece.type != NONE) {
                chessBoard[x - 1][y - 1].isVaild = true;
            }

            // en passant

            // left
            if (chessBoard[x - 1][y].piece.type == PAWN 
                && chessBoard[x - 1][y].piece.color != color 
                && chessBoard[x - 1][y].piece.canEnPassant
                && (x == 3 || x == 4)) 
                {        
                    chessBoard[x - 1][y - 1].isVaild = true;    
                }
            // right
            if (chessBoard[x + 1][y].piece.type == PAWN 
                && chessBoard[x + 1][y].piece.color != color 
                && chessBoard[x + 1][y].piece.canEnPassant
                && (x == 3 || x == 4)) 
                {        
                    chessBoard[x + 1][y - 1].isVaild = true;    
                }                


        break;
        case ROOK:
            // up
            for (int i = y - 1; i >= 0; i--) {
                if (chessBoard[x][i].piece.type == NONE) {
                    chessBoard[x][i].isVaild = true;
                } else {
                    if (chessBoard[x][i].piece.color != color) {
                        chessBoard[x][i].isVaild = true;
                    }
                    break;
                }
            }
            // down
            for (int i = y + 1; i < 8; i++) {
                if (chessBoard[x][i].piece.type == NONE) {
                    chessBoard[x][i].isVaild = true;
                } else {
                    if (chessBoard[x][i].piece.color != color) {
                        chessBoard[x][i].isVaild = true;
                    }
                    break;
                }
            }

            // left
            for (int i = x - 1; i >= 0; i--) {
                if (chessBoard[i][y].piece.type == NONE) {
                    chessBoard[i][y].isVaild = true;
                } else {
                    if (chessBoard[i][y].piece.color != color) {
                        chessBoard[i][y].isVaild = true;
                    }
                    break;
                }
            }

            // right
            for (int i = x + 1; i < 8; i++) {
                if (chessBoard[i][y].piece.type == NONE) {
                    chessBoard[i][y].isVaild = true;
                } else {
                    if (chessBoard[i][y].piece.color != color) {
                        chessBoard[i][y].isVaild = true;
                    }
                    break;
                }
            }
        break;
        case KNIGHT:
            // one left two up
            if (x - 1 >= 0 && y - 2 >= 0 && (chessBoard[x - 1][y - 2].piece.type == NONE || chessBoard[x - 1][y - 2].piece.color != color)) {
                chessBoard[x - 1][y - 2].isVaild = true;
            }
            // one right two up
            if (x + 1 < 8 && y - 2 >= 0 && (chessBoard[x + 1][y - 2].piece.type == NONE || chessBoard[x + 1][y - 2].piece.color != color)) {
                chessBoard[x + 1][y - 2].isVaild = true;
            }
            // one left two down
            if (x - 1 >= 0 && y + 2 < 8 && (chessBoard[x - 1][y + 2].piece.type == NONE || chessBoard[x - 1][y + 2].piece.color != color)) {
                chessBoard[x - 1][y + 2].isVaild = true;
            }
            // one right two down
            if (x + 1 < 8 && y + 2 < 8 && (chessBoard[x + 1][y + 2].piece.type == NONE || chessBoard[x + 1][y + 2].piece.color != color))  {
                chessBoard[x + 1][y + 2].isVaild = true;
            }

            // two left one up
            if (x - 2 >= 0 && y - 1 >= 0 && (chessBoard[x - 2][y - 1].piece.type == NONE || chessBoard[x - 2][y - 1].piece.color != color)) {
                chessBoard[x - 2][y - 1].isVaild = true;
            }
            // two right one up
            if (x + 2 < 8 && y - 1 >= 0 && (chessBoard[x + 2][y - 1].piece.type == NONE || chessBoard[x + 2][y - 1].piece.color != color)) {
                chessBoard[x + 2][y - 1].isVaild = true;
            }
            // two left one down
            if (x - 2 >= 0 && y + 1 < 8 && (chessBoard[x - 2][y + 1].piece.type == NONE || chessBoard[x - 2][y + 1].piece.color != color)) {
                chessBoard[x - 2][y + 1].isVaild = true;
            }
            // two right one down                            
            if (x + 2 < 8 && y + 1 < 8 && (chessBoard[x + 2][y + 1].piece.type == NONE || chessBoard[x + 2][y + 1].piece.color != color)) {
                chessBoard[x + 2][y + 1].isVaild = true;
            }
        break;    
        case BISHOP:
            // right up
            for (int i = 1; x + i < 8 && y - i >= 0; i++) {
                if (chessBoard[x + i][y - i].piece.type == NONE) {
                    chessBoard[x + i][y - i].isVaild = true;
                } else {
                    if (chessBoard[x + i][y - i].piece.color != color) {
                        chessBoard[x + i][y - i].isVaild = true;
                    }
                    break;
                }
            }
            // right down
            for (int i = 1; x + i < 8 && y + i < 8; i++) {
                if (chessBoard[x + i][y + i].piece.type == NONE) {
                    chessBoard[x + i][y + i].isVaild = true;
                } else {
                    if (chessBoard[x + i][y + i].piece.color != color) {
                        chessBoard[x + i][y + i].isVaild = true;
                    }
                    break;
                }
            }
            // left up
            for (int i = 1; x - i >= 0 && y - i >= 0; i++) {
                if (chessBoard[x - i][y - i].piece.type == NONE) {
                    chessBoard[x - i][y - i].isVaild = true;
                } else {
                    if (chessBoard[x - i][y - i].piece.color != color) {
                        chessBoard[x - i][y - i].isVaild = true;
                    }
                    break;
                }
            }
            // left down
            for (int i = 1; x - i >= 0 && y + i < 8; i++) {
                if (chessBoard[x - i][y + i].piece.type == NONE) {
                    chessBoard[x - i][y + i].isVaild = true;
                } else {
                    if (chessBoard[x - i][y + i].piece.color != color) {
                        chessBoard[x - i][y + i].isVaild = true;
                    }
                    break;
                }
            }
        break; 
        case QUEEN:
            // up
            for (int i = y - 1; i >= 0; i--) {
                if (chessBoard[x][i].piece.type == NONE) {
                    chessBoard[x][i].isVaild = true;
                } else {
                    if (chessBoard[x][i].piece.color != color) {
                        chessBoard[x][i].isVaild = true;
                    }
                    break;
                }
            }
            // down
            for (int i = y + 1; i < 8; i++) {
                if (chessBoard[x][i].piece.type == NONE) {
                    chessBoard[x][i].isVaild = true;
                } else {
                    if (chessBoard[x][i].piece.color != color) {
                        chessBoard[x][i].isVaild = true;
                    }
                    break;
                }
            }
            // left
            for (int i = x - 1; i >= 0; i--) {
                if (chessBoard[i][y].piece.type == NONE) {
                    chessBoard[i][y].isVaild = true;
                } else {
                    if (chessBoard[i][y].piece.color != color) {
                        chessBoard[i][y].isVaild = true;
                    }
                    break;
                }
            }
            // right
            for (int i = x + 1; i < 8; i++) {
                if (chessBoard[i][y].piece.type == NONE) {
                    chessBoard[i][y].isVaild = true;
                } else {
                    if (chessBoard[i][y].piece.color != color) {
                        chessBoard[i][y].isVaild = true;
                    }
                    break;
                }
            }
            // right up
            for (int i = 1; x + i < 8 && y - i >= 0; i++) {
                if (chessBoard[x + i][y - i].piece.type == NONE) {
                    chessBoard[x + i][y - i].isVaild = true;
                } else {
                    if (chessBoard[x + i][y - i].piece.color != color) {
                        chessBoard[x + i][y - i].isVaild = true;
                    }
                    break;
                }
            }
            // right down
            for (int i = 1; x + i < 8 && y + i < 8; i++) {
                if (chessBoard[x + i][y + i].piece.type == NONE) {
                    chessBoard[x + i][y + i].isVaild = true;
                } else {
                    if (chessBoard[x + i][y + i].piece.color != color) {
                        chessBoard[x + i][y + i].isVaild = true;
                    }
                    break;
                }
            }
            // left up
            for (int i = 1; x - i >= 0 && y - i >= 0; i++) {
                if (chessBoard[x - i][y - i].piece.type == NONE) {
                    chessBoard[x - i][y - i].isVaild = true;
                } else {
                    if (chessBoard[x - i][y - i].piece.color != color) {
                        chessBoard[x - i][y - i].isVaild = true;
                    }
                    break;
                }
            }
            // left down
            for (int i = 1; x - i >= 0 && y + i < 8; i++) {
                if (chessBoard[x - i][y + i].piece.type == NONE) {
                    chessBoard[x - i][y + i].isVaild = true;
                } else {
                    if (chessBoard[x - i][y + i].piece.color != color) {
                        chessBoard[x - i][y + i].isVaild = true;
                    }
                    break;
                }
            }                 
        break;
        case KING:
            // castle
            if (chessBoard[x][y].piece.type == KING && chessBoard[x][y].piece.moves == 0) {
                // left
                for (int i = x - 1; i >= 0; i--) {
                    if (chessBoard[i][y].piece.type == ROOK) {
                        chessBoard[i][y].isVaild = true;
                        break;
                    } else if (chessBoard[i][y].piece.type != NONE) {
                        break;
                    }
                }

                // right
                for (int i = x + 1; i < 8; i++) {
                    if (chessBoard[i][y].piece.type == ROOK) {
                        chessBoard[i][y].isVaild = true;
                        break;
                    } else if (chessBoard[i][y].piece.type != NONE) {
                        break;
                    }
                }
            }

            // normal king movement

            // up
            if (y != 0 && (chessBoard[x][y - 1].piece.type == NONE || chessBoard[x][y - 1].piece.color != color)) {
                chessBoard[x][y - 1].isVaild = true;
            }
            // up right
            if (y != 0 && x != 7 && (chessBoard[x + 1][y - 1].piece.type == NONE || chessBoard[x + 1][y - 1].piece.color != color)) {
                chessBoard[x + 1][y - 1].isVaild = true;
            }
            // right
            if (x != 7 && (chessBoard[x + 1][y].piece.type == NONE || chessBoard[x + 1][y].piece.color != color)) {
                chessBoard[x + 1][y].isVaild = true;
            }
            // down right
            if (y != 7 && x != 7 && (chessBoard[x + 1][y + 1].piece.type == NONE || chessBoard[x + 1][y + 1].piece.color != color)) {
                chessBoard[x + 1][y + 1].isVaild = true;
            }
            // down
            if (y != 7 && (chessBoard[x][y + 1].piece.type == NONE || chessBoard[x][y + 1].piece.color != color)) {
                chessBoard[x][y + 1].isVaild = true;
            }
            // down left
            if (y != 7 && x != 0 && (chessBoard[x - 1][y + 1].piece.type == NONE || chessBoard[x - 1][y + 1].piece.color != color)) {
                chessBoard[x - 1][y + 1].isVaild = true;
            }
            // left
            if (x != 0 && (chessBoard[x - 1][y].piece.type == NONE || chessBoard[x - 1][y].piece.color != color)) {
                chessBoard[x - 1][y].isVaild = true;
            }
            // left up    
            if (y != 0 && x != 0 && (chessBoard[x - 1][y - 1].piece.type == NONE || chessBoard[x - 1][y - 1].piece.color != color)) {
                chessBoard[x - 1][y - 1].isVaild = true;
            } 
        break;
    }
}

void drawPieces() {
    // non selected piece
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if ((chessBoard[x][y].piece.type != NONE) && (x != selectedPiece.x || y != selectedPiece.y)) {
                DrawTexture(chessBoard[x][y].piece.texture, chessBoard[x][y].piece.rectangle.x, chessBoard[x][y].piece.rectangle.y, WHITE);
            }
        }
    }

    // selected piece
    // this is done so the selected piece renders above the other pieces
    if (selectedPiece.x != -1 && selectedPiece.y != -1) {
        DrawTexture(
            chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.texture,
            chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.rectangle.x,
            chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.rectangle.y,
            WHITE
        );
    }
}

void pieceCleanUp() {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            UnloadTexture(chessBoard[x][y].piece.texture);
        }
    }
}