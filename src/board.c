#include "include/board.h"
#include "include/game.h"
#include <stdio.h>

// board tile color
const Color whiteColor = {212, 212, 212, 255};
const Color blackColor = {148, 148, 148, 255};

Tile chessBoard[8][8];
Tile checkBoard[8][8];

// creates the game board
void createBoard() {
    bool isWhite = true;

    if (color) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                chessBoard[x][y].letter = 'A' + x;
                chessBoard[x][y].number = (7 - y) + 1;
            }
        }
    } else {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                chessBoard[x][y].letter = 'H' - x;
                chessBoard[x][y].number = y + 1;
            }
        }
    }

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            chessBoard[x][y].rectangle = (Rectangle) {x * TILESIZE, y * TILESIZE, TILESIZE, TILESIZE};
            chessBoard[x][y].piece.rectangle = chessBoard[x][y].rectangle;

            if (isWhite) {
                chessBoard[x][y].color = whiteColor;
                isWhite = !isWhite;
            } else {
                chessBoard[x][y].color = blackColor;
                isWhite = !isWhite;
            }
        }
        isWhite = !isWhite;
    }
}

void checkForCheck() { // trash name pls fix
    isWhiteCheck = false;
    isBlackCheck = false;

    Vector2 kingPosition = {-1, -1};

    // get king position
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (chessBoard[x][y].piece.type == KING && chessBoard[x][y].piece.color != color) {
                kingPosition = (Vector2) {x, y};
            }
        }
    }

    bool stop = false;
    for (int x = 0; x < 8; x++) {
        if (stop) {
            break;
        }
        for (int y = 0; y < 8; y++) {
            if (chessBoard[x][y].piece.color == color &&
                isValidMove(x, y, (int) kingPosition.x, (int) kingPosition.y) &&
                chessBoard[x][y].piece.type != KING) {
                for (int x2 = 0; x2 < 8; x2++) {
                    for (int y2 = 0; y2 < 8; y2++) {
                        chessBoard[x2][y2].isValid = false;
                    }
                }

                printf("(%d, %d)\n", x, y);
                getValidMoves(x, y);

                for (int x2 = 0; x2 < 8; x2++) {
                    for (int y2 = 0; y2 < 8; y2++) {
                        checkBoard[x2][y2].isValid = chessBoard[x2][y2].isValid;
                    }
                }

                if (color) {
                    isBlackCheck = true;
                } else {
                    isWhiteCheck = true;
                }
                stop = true;
                break;
            }
        }
    }
}

void rotateBoard() {
    Tile tempBoard[8][8];
    Tile tempCheckBoard[8][8];

    // change color
    color = !color;

    // create temp board
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            tempBoard[x][y] = chessBoard[x][y];
            tempCheckBoard[x][y] = checkBoard[x][y];
        }
    }
    // "flip" board
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            chessBoard[x][y] = tempBoard[7 - x][7 - y];
            checkBoard[x][y] = tempCheckBoard[7 - x][7 - y];
        }
    }

    createBoard();
}

void drawBoard() {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            Color temp = chessBoard[x][y].color;

            if (chessBoard[x][y].isValid) {
                temp.r += 50;
                temp.g += 50;
            } else if (chessBoard[x][y].piece.type == KING) {
                if (isWhiteCheck && chessBoard[x][y].piece.color) {
                    temp.r += 50;
                }
                if (isBlackCheck && !chessBoard[x][y].piece.color) {
                    temp.r += 50;
                }
            }

            // checks for overflow related issues, this isn't the best way, but it works
            if (temp.r < chessBoard[x][y].color.r) { temp.r = 255; }
            if (temp.g < chessBoard[x][y].color.g) { temp.g = 255; }
            if (temp.b < chessBoard[x][y].color.b) { temp.b = 255; } 

            DrawRectangleRec(chessBoard[x][y].rectangle, temp);
        }
    }
}