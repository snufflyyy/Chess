#include "include/input.h"
#include "include/board.h"
#include "include/piece.h"
#include "include/game.h"
#include <raylib.h>
#include <stdio.h>

Vector2 selectedPiece = {-1,-1};
Vector2 selectedPieceOGPos = {-1, -1};

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

        getVaildMoves((int) selectedPiece.x, (int) selectedPiece.y);
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
                    if (chessBoard[x][y].piece.type == ROOK && chessBoard[x][y].piece.color == color) {
                        // rook to the right
                        if (x > 4) {
                            // queen
                            Rectangle temp = chessBoard[x - 1][y].piece.rectangle;
                            chessBoard[x - 1][y].piece = chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece;
                            chessBoard[x - 1][y].piece.rectangle = temp;

                            // rook
                            temp = chessBoard[x - 2][y].piece.rectangle;
                            chessBoard[x - 2][y].piece = chessBoard[x][y].piece;
                            chessBoard[x - 2][y].piece.rectangle = temp;
                        } else { // rook to the left
                            // queen
                            Rectangle temp = chessBoard[x + 2][y].piece.rectangle;
                            chessBoard[x + 2][y].piece = chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece;
                            chessBoard[x + 2][y].piece.rectangle = temp;
                            chessBoard[x + 2][y].piece.moves++;

                            // rook
                            temp = chessBoard[x + 3][y].piece.rectangle;
                            chessBoard[x + 3][y].piece = chessBoard[x][y].piece;
                            chessBoard[x + 3][y].piece.rectangle = temp;
                            chessBoard[x + 3][y].piece.moves++;
                        }

                        chessBoard[x][y].piece.type = NONE;
                        chessBoard[x][y].piece.moves = 0;
                    } else {
                        Rectangle temp = chessBoard[x][y].piece.rectangle;
                        chessBoard[x][y].piece = chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece;
                        chessBoard[x][y].piece.rectangle = temp;
                        chessBoard[x][y].piece.moves++;

                        // remove piece being effected by en passant
                        if (chessBoard[x][y + 1].piece.canEnPassant) {
                            chessBoard[x][y + 1].piece.type = NONE;
                            chessBoard[x][y + 1].piece.moves = 0;
                        }

                        // sets all piece's canEnPassant to false
                        for (int x2 = 0; x2 < 8; x2++) {
                            for (int y2 = 0; y2 < 8; y2++) {
                                chessBoard[x2][y2].piece.canEnPassant = false;
                            }
                        }

                        // checks if a piece can be en passanted
                        if (chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.type == PAWN && (int) selectedPiece.y - 2 == y) {
                            chessBoard[x][y].piece.canEnPassant = true;
                        }
                    }

                    chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.type = NONE;
                    chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.moves = 0;

                    checkForCheck();

                    rotateBoard();
                } else {
                    if (selectedPieceOGPos.x != -1 && selectedPieceOGPos.y != -1) {
                        chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.rectangle.x = selectedPieceOGPos.x;
                        chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.rectangle.y = selectedPieceOGPos.y;
                    }
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