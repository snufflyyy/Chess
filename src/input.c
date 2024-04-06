#include "include/input.h"
#include "include/board.h"
#include "include/piece.h"
#include "include/variables.h"
#include <raylib.h>
#include <stdio.h>

Vector2 selectedPiece = {-1,-1};
Vector2 selectedPieceOGPos = {-1, -1};

Tile tempBoard[8][8];

void input() {
    // selects a piece
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                if (chessBoard[x][y].piece.type != NONE && chessBoard[x][y].piece.color == color &&CheckCollisionPointRec(GetMousePosition(), chessBoard[x][y].piece.rectangle)) {
                    selectedPiece.x = x;
                    selectedPiece.y = y;

                    selectedPieceOGPos = (Vector2) {chessBoard[x][y].piece.rectangle.x, chessBoard[x][y].piece.rectangle.y};
                }
            }
        }

        getVaildMoves((int) selectedPiece.x, (int) selectedPiece.y, color);
    }

    // moves piece based on where the mouse is
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        if (selectedPiece.x != -1 && selectedPiece.y != -1) {
            chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.rectangle.x = GetMouseX() - chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.texture.width / 2;
            chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.rectangle.y = GetMouseY() - chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.texture.height / 2;
        }
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                if (chessBoard[x][y].isVaild && CheckCollisionPointRec(GetMousePosition(), chessBoard[x][y].rectangle)) {
                    chessBoard[x][y].piece.type = chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.type;
                    chessBoard[x][y].piece.color = chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.color;
                    chessBoard[x][y].piece.texture = chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.texture;
                    chessBoard[x][y].piece.moves = chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.moves + 1;

                    chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.type = NONE;
                    chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.moves = 0;

                    for (int x = 0; x < 8; x++) {
                        for (int y = 0; y < 8; y++) {
                            tempBoard[x][y] = chessBoard[x][y];
                        }
                    }

                    for (int x = 0; x < 8; x++) {
                        for (int y = 0; y < 8; y++) {
                            chessBoard[x][y] = tempBoard[8 - 1 - x][8 - 1 - y];
                        }
                    }

                    color = !color;
                    createBoard();
                } else {
                    chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.rectangle.x = selectedPieceOGPos.x;
                    chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.rectangle.y = selectedPieceOGPos.y;
                }
            }
        }

        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                if (chessBoard[x][y].isVaild) {
                    chessBoard[x][y].isVaild = false;
                }
            }
        }

        selectedPiece = (Vector2) {-1, -1};
        selectedPieceOGPos = (Vector2) {-1, -1};
    }
}