#include <raylib.h>
#include "include/game.h"
#include "include/board.h"

Tile chessBoard[BOARDSIZE][BOARDSIZE];
bool checkBoard[BOARDSIZE][BOARDSIZE];

void createBoard() {
    bool color = true; // top left of board is always white

    for (int x = 0; x < BOARDSIZE; x++) {
        for (int y = 0; y < BOARDSIZE; y++) {
            if (currentColor == true) { // white
                chessBoard[x][y].letter = 'A' + x;
                chessBoard[x][y].number = BOARDSIZE - y;
            } else { // black
                chessBoard[x][y].letter = 'H' - x;
                chessBoard[x][y].number = y + 1;
            }

            chessBoard[x][y].rectangle = (Rectangle) {
                x * tileScale + (windowWidth / 2) - ((tileScale * BOARDSIZE) / 2),
                y * tileScale + borderThinkness,
                tileScale,
                tileScale
            };

            chessBoard[x][y].piece.rectangle = chessBoard[x][y].rectangle;

            if (color == true) { // white
                chessBoard[x][y].color = lightTileColor;
                color = !color;
            } else { // black
                chessBoard[x][y].color = darkTileColor;
                color = !color;
            }
        }
        color = !color;
    }
}

void rotateBoard() {
    Tile tempBoard[BOARDSIZE][BOARDSIZE];

    // change color
    currentColor = !currentColor;

    // create temp board
    for (int x = 0; x < BOARDSIZE; x++) {
        for (int y = 0; y < BOARDSIZE; y++) {
            tempBoard[x][y] = chessBoard[x][y];
        }
    }
    // "flip" board
    for (int x = 0; x < BOARDSIZE; x++) {
        for (int y = 0; y < BOARDSIZE; y++) {
            chessBoard[x][y] = tempBoard[7 - x][7 - y];
        }
    }

    createBoard();
}

void drawBoard() {
    for (int x = 0; x < BOARDSIZE; x++) {
        for (int y = 0; y < BOARDSIZE; y++) {
            Color temp = chessBoard[x][y].color;

            // check for overflow issues with the colors, not the best way but works
            if (temp.r < chessBoard[x][y].color.r) { temp.r = 255; };
            if (temp.g < chessBoard[x][y].color.g) { temp.g = 255; };
            if (temp.b < chessBoard[x][y].color.b) { temp.b = 255; };

            DrawRectangleV (
                (Vector2) {
                    chessBoard[x][y].rectangle.x,
                    chessBoard[x][y].rectangle.y
                },
                (Vector2) {
                    tileScale, tileScale
                },
                temp
            );
        }
    }
}

void drawLetters() {
    char letter;

    for (int i = 0; i < BOARDSIZE; i++) {
        if (currentColor == true) { // white
            letter = 'A' + i;
        } else { // black
            letter = 'H' - i;
        }

        DrawText(TextFormat("%c", letter), chessBoard[0][BOARDSIZE - 1].rectangle.x + tileScale * i, (BOARDSIZE * tileScale) + borderThinkness, 20, WHITE);
    }
}

void drawNumbers() {
    int number;

    for (int i = 0; i < BOARDSIZE; i++) {
        if (currentColor == true) { // white
            number = BOARDSIZE - i;
        } else { // black
            number = i + 1;
        }

        // the minus 2 and 1.5 is so the numbers look perfect, retarded
        // also this approach is fundamentally wrong and causes stuff to look weird at different sizes, fix later
        DrawText(TextFormat("%d", number), chessBoard[0][0].rectangle.x - (borderThinkness / 2) - 2, (tileScale * i) + borderThinkness - 1.5f, 20, WHITE);
    }
}