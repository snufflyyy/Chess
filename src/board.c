#include "include/board.h"
#include "include/variables.h"
#include <stdio.h>

// board tile color
const Color whiteColor = {212, 212, 212, 255};
const Color blackColor = {148, 148, 148, 255};

Tile chessBoard[8][8];
Tile tempBoard[8][8];

// creates the game board
void createBoard() {
    bool isWhite = color;

    // black
    if (color == false) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                chessBoard[x][y].rectangle = (Rectangle) {x * TILESIZE, y * TILESIZE, TILESIZE, TILESIZE};
                chessBoard[x][y].piece.rectangle = chessBoard[x][y].rectangle;

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
    // create temp board
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            tempBoard[x][y] = chessBoard[x][y];
        }
    }
    // "flip" board
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            chessBoard[x][y] = tempBoard[7 - x][7 - y];
        }
    }
    // change color
    color = !color;
    createBoard();
}

void drawBoard() {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (chessBoard[x][y].isVaild == false) {
                DrawRectangleRec(chessBoard[x][y].rectangle, chessBoard[x][y].color);
            } else {
                Color temp = chessBoard[x][y].color;
                // makes the squares look yellow
                temp.r += 50;
                temp.g += 50;

                // checks for overflow related issues, this isn't the best way but it works
                if (temp.r < chessBoard[x][y].color.r) { temp.r = 255; }
                if (temp.g < chessBoard[x][y].color.g) { temp.g = 255; }
                if (temp.b < chessBoard[x][y].color.b) { temp.b = 255; } 

                DrawRectangleRec(chessBoard[x][y].rectangle, temp);
            }
        }
    }
}