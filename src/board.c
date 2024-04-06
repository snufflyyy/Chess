#include "include/board.h"
#include "include/variables.h"

// board tile color
const Color whiteColor = {212, 212, 212, 255};
const Color blackColor = {148, 148, 148, 255};

Tile chessBoard[8][8];

// creates the game board
void createBoard() {
    bool isWhite = color;

    // black
    if (color == false) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                chessBoard[x][y].rectangle = (Rectangle) {x * TILESIZE, y * TILESIZE, TILESIZE, TILESIZE};
                chessBoard[x][y].piece.rectangle = chessBoard[x][y].rectangle;

                switch (x) {
                    case 0: chessBoard[x][y].letter = 'A'; break;
                    case 1: chessBoard[x][y].letter = 'B'; break;
                    case 2: chessBoard[x][y].letter = 'C'; break;
                    case 3: chessBoard[x][y].letter = 'D'; break;
                    case 4: chessBoard[x][y].letter = 'E'; break;
                    case 5: chessBoard[x][y].letter = 'F'; break;
                    case 6: chessBoard[x][y].letter = 'G'; break;
                    case 7: chessBoard[x][y].letter = 'H'; break;
                }

                chessBoard[x][y].number = y + 1;

                if (isWhite) {
                    chessBoard[x][y].color = whiteColor;
                    isWhite = false;
                } else {
                    chessBoard[x][y].color = blackColor;
                    isWhite = true;
                }
            }
            isWhite = !isWhite;
        }
    } else {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                chessBoard[x][y].rectangle = (Rectangle) {x * TILESIZE, y * TILESIZE, TILESIZE, TILESIZE};
                chessBoard[x][y].piece.rectangle = chessBoard[x][y].rectangle;

                switch (x) {
                    case 0: chessBoard[x][y].letter = 'A'; break;
                    case 1: chessBoard[x][y].letter = 'B'; break;
                    case 2: chessBoard[x][y].letter = 'C'; break;
                    case 3: chessBoard[x][y].letter = 'D'; break;
                    case 4: chessBoard[x][y].letter = 'E'; break;
                    case 5: chessBoard[x][y].letter = 'F'; break;
                    case 6: chessBoard[x][y].letter = 'G'; break;
                    case 7: chessBoard[x][y].letter = 'H'; break;
                }

                // there has to be a better way of doing this
                switch (y) {
                    case 0: chessBoard[x][y].number = 8; break;
                    case 1: chessBoard[x][y].number = 7; break;
                    case 2: chessBoard[x][y].number = 6; break;
                    case 3: chessBoard[x][y].number = 5; break;
                    case 4: chessBoard[x][y].number = 4; break;
                    case 5: chessBoard[x][y].number = 3; break;
                    case 6: chessBoard[x][y].number = 2; break;
                    case 7: chessBoard[x][y].number = 1; break;
                }

                if (isWhite) {
                    chessBoard[x][y].color = whiteColor;
                    isWhite = false;
                } else {
                    chessBoard[x][y].color = blackColor;
                    isWhite = true;
                }
            }
            isWhite = !isWhite;
        }
    }
}

void rotateBoard() {
    
}

void drawBoard() {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (chessBoard[x][y].isVaild == false) {
                DrawRectangleRec(chessBoard[x][y].rectangle, chessBoard[x][y].color);
            } else {
                DrawRectangleRec (
                    chessBoard[x][y].rectangle, 
                    (Color) {
                        chessBoard[x][y].color.r + 40,
                        chessBoard[x][y].color.g + 40, 
                        chessBoard[x][y].color.b, 
                        chessBoard[x][y].color.a
                    }
                );
            }
        }
    }
}

void boardCleanUp() {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            UnloadTexture(chessBoard[x][y].piece.texture);
        }
    }
}