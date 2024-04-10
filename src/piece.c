#include "include/piece.h"
#include "include/game.h"
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

void getValidMoves(int x, int y) {
    switch (chessBoard[x][y].piece.type) {
        case NONE: /** do nothing :) **/ break;
        case PAWN:
            if (isWhiteCheck || isBlackCheck) {
                // normal moves

                // first move
                if (chessBoard[x][y].piece.moves == 0 && checkBoard[x][y].isValid) {
                    chessBoard[x][y - 1].isValid = true;
                    chessBoard[x][y - 2].isValid = true;
                } else if (chessBoard[x][y - 1].piece.type == NONE && checkBoard[x][y - 1].isValid) { // after first move
                    chessBoard[x][y - 1].isValid = true;
                }

                // capture

                // right
                if (chessBoard[x + 1][y - 1].piece.color != color && chessBoard[x + 1][y - 1].piece.type != NONE && checkBoard[x + 1][y - 1].isValid) {
                    chessBoard[x + 1][y - 1].isValid = true;
                }
                // left
                if (chessBoard[x - 1][y - 1].piece.color != color && chessBoard[x - 1][y - 1].piece.type != NONE && checkBoard[x - 1][y - 1].isValid) {
                    chessBoard[x - 1][y - 1].isValid = true;
                }

                // en passant (--* needed to do check thing *--)

                // left
                if (chessBoard[x - 1][y].piece.type == PAWN
                    && chessBoard[x - 1][y].piece.color != color
                    && chessBoard[x - 1][y].piece.canEnPassant
                    && (x == 3 || x == 4))
                {
                    chessBoard[x - 1][y - 1].isValid = true;
                }
                // right
                if (chessBoard[x + 1][y].piece.type == PAWN
                    && chessBoard[x + 1][y].piece.color != color
                    && chessBoard[x + 1][y].piece.canEnPassant
                    && (x == 3 || x == 4))
                {
                    chessBoard[x + 1][y - 1].isValid = true;
                }
            } else {
                // normal moves

                // first move
                if (chessBoard[x][y].piece.moves == 0) {
                    chessBoard[x][y - 1].isValid = true;
                    chessBoard[x][y - 2].isValid = true;
                } else if (chessBoard[x][y - 1].piece.type == NONE) { // after first move
                    chessBoard[x][y - 1].isValid = true;
                }

                // capture

                // right
                if (chessBoard[x + 1][y - 1].piece.color != color && chessBoard[x + 1][y - 1].piece.type != NONE) {
                    chessBoard[x + 1][y - 1].isValid = true;
                }
                // left
                if (chessBoard[x - 1][y - 1].piece.color != color && chessBoard[x - 1][y - 1].piece.type != NONE) {
                    chessBoard[x - 1][y - 1].isValid = true;
                }

                // en passant

                // left
                if (chessBoard[x - 1][y].piece.type == PAWN
                    && chessBoard[x - 1][y].piece.color != color
                    && chessBoard[x - 1][y].piece.canEnPassant
                    && (x == 3 || x == 4))
                {
                    chessBoard[x - 1][y - 1].isValid = true;
                }
                // right
                if (chessBoard[x + 1][y].piece.type == PAWN
                    && chessBoard[x + 1][y].piece.color != color
                    && chessBoard[x + 1][y].piece.canEnPassant
                    && (x == 3 || x == 4))
                {
                    chessBoard[x + 1][y - 1].isValid = true;
                }
            }
        break;
        case ROOK:
            // up
            for (int i = y - 1; i >= 0; i--) {
                if (chessBoard[x][i].piece.type == NONE) {
                    chessBoard[x][i].isValid = true;
                } else {
                    if (chessBoard[x][i].piece.color != color) {
                        chessBoard[x][i].isValid = true;
                    }
                    break;
                }
            }
            // down
            for (int i = y + 1; i < 8; i++) {
                if (chessBoard[x][i].piece.type == NONE) {
                    chessBoard[x][i].isValid = true;
                } else {
                    if (chessBoard[x][i].piece.color != color) {
                        chessBoard[x][i].isValid = true;
                    }
                    break;
                }
            }

            // left
            for (int i = x - 1; i >= 0; i--) {
                if (chessBoard[i][y].piece.type == NONE) {
                    chessBoard[i][y].isValid = true;
                } else {
                    if (chessBoard[i][y].piece.color != color) {
                        chessBoard[i][y].isValid = true;
                    }
                    break;
                }
            }

            // right
            for (int i = x + 1; i < 8; i++) {
                if (chessBoard[i][y].piece.type == NONE) {
                    chessBoard[i][y].isValid = true;
                } else {
                    if (chessBoard[i][y].piece.color != color) {
                        chessBoard[i][y].isValid = true;
                    }
                    break;
                }
            }
        break;
        case KNIGHT:
            // one left two up
            if (x - 1 >= 0 && y - 2 >= 0 && (chessBoard[x - 1][y - 2].piece.type == NONE || chessBoard[x - 1][y - 2].piece.color != color)) {
                chessBoard[x - 1][y - 2].isValid = true;
            }
            // one right two up
            if (x + 1 < 8 && y - 2 >= 0 && (chessBoard[x + 1][y - 2].piece.type == NONE || chessBoard[x + 1][y - 2].piece.color != color)) {
                chessBoard[x + 1][y - 2].isValid = true;
            }
            // one left two down
            if (x - 1 >= 0 && y + 2 < 8 && (chessBoard[x - 1][y + 2].piece.type == NONE || chessBoard[x - 1][y + 2].piece.color != color)) {
                chessBoard[x - 1][y + 2].isValid = true;
            }
            // one right two down
            if (x + 1 < 8 && y + 2 < 8 && (chessBoard[x + 1][y + 2].piece.type == NONE || chessBoard[x + 1][y + 2].piece.color != color))  {
                chessBoard[x + 1][y + 2].isValid = true;
            }

            // two left one up
            if (x - 2 >= 0 && y - 1 >= 0 && (chessBoard[x - 2][y - 1].piece.type == NONE || chessBoard[x - 2][y - 1].piece.color != color)) {
                chessBoard[x - 2][y - 1].isValid = true;
            }
            // two right one up
            if (x + 2 < 8 && y - 1 >= 0 && (chessBoard[x + 2][y - 1].piece.type == NONE || chessBoard[x + 2][y - 1].piece.color != color)) {
                chessBoard[x + 2][y - 1].isValid = true;
            }
            // two left one down
            if (x - 2 >= 0 && y + 1 < 8 && (chessBoard[x - 2][y + 1].piece.type == NONE || chessBoard[x - 2][y + 1].piece.color != color)) {
                chessBoard[x - 2][y + 1].isValid = true;
            }
            // two right one down                            
            if (x + 2 < 8 && y + 1 < 8 && (chessBoard[x + 2][y + 1].piece.type == NONE || chessBoard[x + 2][y + 1].piece.color != color)) {
                chessBoard[x + 2][y + 1].isValid = true;
            }
        break;    
        case BISHOP:
            if (isBlackCheck || isWhiteCheck) {
                // right up
                for (int i = 1; x + i < 8 && y - i >= 0; i++) {
                    if (chessBoard[x + i][y - i].piece.type == NONE && checkBoard[x + i][y - i].isValid) {
                        chessBoard[x + i][y - i].isValid = true;
                    } else {
                        if (chessBoard[x + i][y - i].piece.color != color && checkBoard[x + i][y - i].isValid) {
                            chessBoard[x + i][y - i].isValid = true;
                        }
                        break;
                    }
                }
                // right down
                for (int i = 1; x + i < 8 && y + i < 8; i++) {
                    if (chessBoard[x + i][y + i].piece.type == NONE && checkBoard[x + i][y + i].isValid) {
                        chessBoard[x + i][y + i].isValid = true;
                    } else {
                        if (chessBoard[x + i][y + i].piece.color != color && checkBoard[x + i][y + i].isValid) {
                            chessBoard[x + i][y + i].isValid = true;
                        }
                        break;
                    }
                }
                // left up
                for (int i = 1; x - i >= 0 && y - i >= 0; i++) {
                    if (chessBoard[x - i][y - i].piece.type == NONE && checkBoard[x - i][y - i].isValid) {
                        chessBoard[x - i][y - i].isValid = true;
                    } else {
                        if (chessBoard[x - i][y - i].piece.color != color && checkBoard[x - i][y - i].isValid) {
                            chessBoard[x - i][y - i].isValid = true;
                        }
                        break;
                    }
                }
                // left down
                for (int i = 1; x - i >= 0 && y + i < 8; i++) {
                    if (chessBoard[x - i][y + i].piece.type == NONE && checkBoard[x - i][y + i].isValid) {
                        chessBoard[x - i][y + i].isValid = true;
                    } else {
                        if (chessBoard[x - i][y + i].piece.color != color && checkBoard[x - i][y + i].isValid) {
                            chessBoard[x - i][y + i].isValid = true;
                        }
                        break;
                    }
                }
            } else {
                // right up
                for (int i = 1; x + i < 8 && y - i >= 0; i++) {
                    if (chessBoard[x + i][y - i].piece.type == NONE) {
                        chessBoard[x + i][y - i].isValid = true;
                    } else {
                        if (chessBoard[x + i][y - i].piece.color != color) {
                            chessBoard[x + i][y - i].isValid = true;
                        }
                        break;
                    }
                }
                // right down
                for (int i = 1; x + i < 8 && y + i < 8; i++) {
                    if (chessBoard[x + i][y + i].piece.type == NONE) {
                        chessBoard[x + i][y + i].isValid = true;
                    } else {
                        if (chessBoard[x + i][y + i].piece.color != color) {
                            chessBoard[x + i][y + i].isValid = true;
                        }
                        break;
                    }
                }
                // left up
                for (int i = 1; x - i >= 0 && y - i >= 0; i++) {
                    if (chessBoard[x - i][y - i].piece.type == NONE) {
                        chessBoard[x - i][y - i].isValid = true;
                    } else {
                        if (chessBoard[x - i][y - i].piece.color != color) {
                            chessBoard[x - i][y - i].isValid = true;
                        }
                        break;
                    }
                }
                // left down
                for (int i = 1; x - i >= 0 && y + i < 8; i++) {
                    if (chessBoard[x - i][y + i].piece.type == NONE) {
                        chessBoard[x - i][y + i].isValid = true;
                    } else {
                        if (chessBoard[x - i][y + i].piece.color != color) {
                            chessBoard[x - i][y + i].isValid = true;
                        }
                        break;
                    }
                }
            }
        break; 
        case QUEEN:
            // up
            for (int i = y - 1; i >= 0; i--) {
                if (chessBoard[x][i].piece.type == NONE) {
                    chessBoard[x][i].isValid = true;
                } else {
                    if (chessBoard[x][i].piece.color != color) {
                        chessBoard[x][i].isValid = true;
                    }
                    break;
                }
            }
            // down
            for (int i = y + 1; i < 8; i++) {
                if (chessBoard[x][i].piece.type == NONE) {
                    chessBoard[x][i].isValid = true;
                } else {
                    if (chessBoard[x][i].piece.color != color) {
                        chessBoard[x][i].isValid = true;
                    }
                    break;
                }
            }
            // left
            for (int i = x - 1; i >= 0; i--) {
                if (chessBoard[i][y].piece.type == NONE) {
                    chessBoard[i][y].isValid = true;
                } else {
                    if (chessBoard[i][y].piece.color != color) {
                        chessBoard[i][y].isValid = true;
                    }
                    break;
                }
            }
            // right
            for (int i = x + 1; i < 8; i++) {
                if (chessBoard[i][y].piece.type == NONE) {
                    chessBoard[i][y].isValid = true;
                } else {
                    if (chessBoard[i][y].piece.color != color) {
                        chessBoard[i][y].isValid = true;
                    }
                    break;
                }
            }
            // right up
            for (int i = 1; x + i < 8 && y - i >= 0; i++) {
                if (chessBoard[x + i][y - i].piece.type == NONE) {
                    chessBoard[x + i][y - i].isValid = true;
                } else {
                    if (chessBoard[x + i][y - i].piece.color != color) {
                        chessBoard[x + i][y - i].isValid = true;
                    }
                    break;
                }
            }
            // right down
            for (int i = 1; x + i < 8 && y + i < 8; i++) {
                if (chessBoard[x + i][y + i].piece.type == NONE) {
                    chessBoard[x + i][y + i].isValid = true;
                } else {
                    if (chessBoard[x + i][y + i].piece.color != color) {
                        chessBoard[x + i][y + i].isValid = true;
                    }
                    break;
                }
            }
            // left up
            for (int i = 1; x - i >= 0 && y - i >= 0; i++) {
                if (chessBoard[x - i][y - i].piece.type == NONE) {
                    chessBoard[x - i][y - i].isValid = true;
                } else {
                    if (chessBoard[x - i][y - i].piece.color != color) {
                        chessBoard[x - i][y - i].isValid = true;
                    }
                    break;
                }
            }
            // left down
            for (int i = 1; x - i >= 0 && y + i < 8; i++) {
                if (chessBoard[x - i][y + i].piece.type == NONE) {
                    chessBoard[x - i][y + i].isValid = true;
                } else {
                    if (chessBoard[x - i][y + i].piece.color != color) {
                        chessBoard[x - i][y + i].isValid = true;
                    }
                    break;
                }
            }                 
        break;
        case KING:
        for (int x2 = 0; x2 < 8; x2++) {
            for (int y2 = 0; y2 < 8; y2++) {
                // castle
                if (chessBoard[x][y].piece.type == KING && chessBoard[x][y].piece.moves == 0) {
                    // left
                    for (int i = x - 1; i >= 0; i--) {
                        if (chessBoard[i][y].piece.type == ROOK && !checkBoard[i][y].isValid) {
                            chessBoard[i][y].isValid = true;
                            break;
                        } else if (chessBoard[i][y].piece.type != NONE) {
                            break;
                        }
                    }

                    // right
                    for (int i = x + 1; i < 8; i++) {
                        if (chessBoard[i][y].piece.type == ROOK && !checkBoard[i][y].isValid) {
                            chessBoard[i][y].isValid = true;
                            break;
                        } else if (chessBoard[i][y].piece.type != NONE) {
                            break;
                        }
                    }
                }

                // normal king movement

                // up
                if (y != 0 && (chessBoard[x][y - 1].piece.type == NONE || chessBoard[x][y - 1].piece.color != color) && !checkBoard[x][y - 1].isValid) {
                    chessBoard[x][y - 1].isValid = true;
                }
                // up right
                if (y != 0 && x != 7 && (chessBoard[x + 1][y - 1].piece.type == NONE || chessBoard[x + 1][y - 1].piece.color != color) && !checkBoard[x + 1][y - 1].isValid) {
                    chessBoard[x + 1][y - 1].isValid = true;
                }
                // right
                if (x != 7 && (chessBoard[x + 1][y].piece.type == NONE || chessBoard[x + 1][y].piece.color != color) && !checkBoard[x + 1][y].isValid) {
                    chessBoard[x + 1][y].isValid = true;
                }
                // down right
                if (y != 7 && x != 7 && (chessBoard[x + 1][y + 1].piece.type == NONE || chessBoard[x + 1][y + 1].piece.color != color) && !checkBoard[x + 1][y + 1].isValid) {
                    chessBoard[x + 1][y + 1].isValid = true;
                }
                // down
                if (y != 7 && (chessBoard[x][y + 1].piece.type == NONE || chessBoard[x][y + 1].piece.color != color) && !checkBoard[x][y - 1].isValid) {
                    chessBoard[x][y + 1].isValid = true;
                }
                // down left
                if (y != 7 && x != 0 && (chessBoard[x - 1][y + 1].piece.type == NONE || chessBoard[x - 1][y + 1].piece.color != color) && !checkBoard[x - 1][y + 1].isValid) {
                    chessBoard[x - 1][y + 1].isValid = true;
                }
                // left
                if (x != 0 && (chessBoard[x - 1][y].piece.type == NONE || chessBoard[x - 1][y].piece.color != color) && !checkBoard[x - 1][y].isValid) {
                    chessBoard[x - 1][y].isValid = true;
                }
                // left up    
                if (y != 0 && x != 0 && (chessBoard[x - 1][y - 1].piece.type == NONE || chessBoard[x - 1][y - 1].piece.color != color) && !checkBoard[x - 1][y - 1].isValid) {
                    chessBoard[x - 1][y - 1].isValid = true;
                } 
            }
        }
        break;
    }
}

bool isValidMove(int x, int y, int x2, int y2) {
    getValidMoves(x, y);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (chessBoard[x2][y2].isValid) {
                return true;
            }
        }
    }

    return false;
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