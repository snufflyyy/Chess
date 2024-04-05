#include "include/input.h"
#include "include/board.h"
#include "include/piece.h"
#include <raylib.h>

Vector2 selectedPiece = {-1,-1};
Vector2 selectedPieceOGPos = {-1, -1};

void input(bool color) {
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
    }

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        if (selectedPiece.x != -1 && selectedPiece.y != -1) {
            chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.rectangle.x = GetMouseX() - chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.texture.width / 2;
            chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.rectangle.y = GetMouseY() - chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.texture.height / 2;
        }
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                if (chessBoard[x][y].piece.type == NONE && CheckCollisionPointRec(GetMousePosition(), chessBoard[x][y].rectangle)) {
                    chessBoard[x][y].piece.type = chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.type;
                    chessBoard[x][y].piece.color = chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.color;
                    chessBoard[x][y].piece.texture = chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.texture;

                    chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.type = NONE;
                } else {
                    chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.rectangle.x = selectedPieceOGPos.x;
                    chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.rectangle.y = selectedPieceOGPos.y;
                }
            }
        }
    }
}