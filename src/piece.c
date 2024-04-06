#include "include/piece.h"
#include "include/variables.h"
#include "include/board.h"
#include "include/input.h"

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
            // white

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
            // white knight
            if (chessBoard[x][y].letter == 'B' && chessBoard[x][y].number == 1) {
                chessBoard[x][y].piece.type = KNIGHT;
                chessBoard[x][y].piece.color = true;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteKnight);
            }
            // white bishop
            if (chessBoard[x][y].letter == 'C' && chessBoard[x][y].number == 1) {
                chessBoard[x][y].piece.type = BISHOP;
                chessBoard[x][y].piece.color = true;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteBishop);
            }
            // white queen
            if (chessBoard[x][y].letter == 'D' && chessBoard[x][y].number == 1) {
                chessBoard[x][y].piece.type = QUEEN;
                chessBoard[x][y].piece.color = true;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteQueen);
            }
            // white king
            if (chessBoard[x][y].letter == 'E' && chessBoard[x][y].number == 1) {
                chessBoard[x][y].piece.type = KING;
                chessBoard[x][y].piece.color = true;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteKing);
            }            
            // white bishop
            if (chessBoard[x][y].letter == 'F' && chessBoard[x][y].number == 1) {
                chessBoard[x][y].piece.type = BISHOP;
                chessBoard[x][y].piece.color = true;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteBishop);
            }
            // white knight
            if (chessBoard[x][y].letter == 'G' && chessBoard[x][y].number == 1) {
                chessBoard[x][y].piece.type = KNIGHT;
                chessBoard[x][y].piece.color = true;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteKnight);
            }
            // white rook
            if (chessBoard[x][y].letter == 'H' && chessBoard[x][y].number == 1) {
                chessBoard[x][y].piece.type = ROOK;
                chessBoard[x][y].piece.color = true;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(whiteRook);
            }
            // black

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
            // black knight 
            if (chessBoard[x][y].letter == 'B' && chessBoard[x][y].number == 8) {
                chessBoard[x][y].piece.type = KNIGHT;
                chessBoard[x][y].piece.color = false;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(blackKnight);
            }
            // black bishop
            if (chessBoard[x][y].letter == 'C' && chessBoard[x][y].number == 8) {
                chessBoard[x][y].piece.type = BISHOP;
                chessBoard[x][y].piece.color = false;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(blackBishop);
            }
            // black queen
            if (chessBoard[x][y].letter == 'D' && chessBoard[x][y].number == 8) {
                chessBoard[x][y].piece.type = QUEEN;
                chessBoard[x][y].piece.color = false;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(blackQueen);
            }
            // black king
            if (chessBoard[x][y].letter == 'E' && chessBoard[x][y].number == 8) {
                chessBoard[x][y].piece.type = KING;
                chessBoard[x][y].piece.color = false;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(blackKing);
            }
            // black bishop
            if (chessBoard[x][y].letter == 'F' && chessBoard[x][y].number == 8) {
                chessBoard[x][y].piece.type = BISHOP;
                chessBoard[x][y].piece.color = false;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(blackBishop);
            }       
            // black knight 
            if (chessBoard[x][y].letter == 'G' && chessBoard[x][y].number == 8) {
                chessBoard[x][y].piece.type = KNIGHT;
                chessBoard[x][y].piece.color = false;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(blackKnight);
            }  
            // black rook 
            if (chessBoard[x][y].letter == 'H' && chessBoard[x][y].number == 8) {
                chessBoard[x][y].piece.type = ROOK;
                chessBoard[x][y].piece.color = false;
                chessBoard[x][y].piece.texture = LoadTextureFromImage(blackRook);
            }

            chessBoard[x][y].piece.letter = chessBoard[x][y].letter;
            chessBoard[x][y].piece.number = chessBoard[x][y].number;                 
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

void getVaildMoves(int x, int y, bool color) {
    switch (chessBoard[x][y].piece.type) {
        case NONE: /** do nothing :) **/ break;
        case PAWN:
            if (chessBoard[x][y].piece.moves == 0) {
                chessBoard[x][y - 1].isVaild = true;
                chessBoard[x][y - 2].isVaild = true;
            } else if (chessBoard[x][y - 1].piece.type == NONE) {
                chessBoard[x][y - 1].isVaild = true;
            }

            if (chessBoard[x + 1][y - 1].piece.color != color && chessBoard[x + 1][y - 1].piece.type != NONE) {
                chessBoard[x + 1][y - 1].isVaild = true;
            }
            if (chessBoard[x - 1][y - 1].piece.color != color && chessBoard[x - 1][y - 1].piece.type != NONE) {
                chessBoard[x - 1][y - 1].isVaild = true;
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
                DrawTexture(
                    chessBoard[x][y].piece.texture,
                    chessBoard[x][y].piece.rectangle.x,
                    chessBoard[x][y].piece.rectangle.y,
                    WHITE
                );
            }
        }
    }

    if (selectedPiece.x != -1 && selectedPiece.y != -1) {
        DrawTexture(
            chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.texture,
            chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.rectangle.x,
            chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.rectangle.y,
            WHITE
        );
    }
}