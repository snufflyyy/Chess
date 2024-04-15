#include <raylib.h>

#include "include/game.h"
#include "include/board.h"

void selectPiece() {
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			if (chessBoard[x][y].piece.type != NONE && chessBoard[x][y].piece.color == currentColor && CheckCollisionPointRec(GetMousePosition(), chessBoard[x][y].piece.rectangle)) {
				selectedPiece.x = x;
				selectedPiece.y = y;
			}
		}
	}
}

void movePieceToMouse() {
	if (selectedPiece.x != -1 && selectedPiece.y != -1) {
		chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.rectangle.x = GetMouseX() - chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.texture.width / 2;
		chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.rectangle.y = GetMouseY() - chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.texture.height / 2;
	}
}

void placePiece() {
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			if (chessBoard[x][y].isValid && CheckCollisionPointRec(GetMousePosition(), chessBoard[x][y].rectangle)) {
				// do stuff
			} else {
				if (selectedPiece.x != -1 && selectedPiece.y != -1) {
					chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.rectangle.x = chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].rectangle.x;
					chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].piece.rectangle.y = chessBoard[(int) selectedPiece.x][(int) selectedPiece.y].rectangle.y;
				}
			}
		}
	}

	selectedPiece = (Vector2) {-1, -1};
}

void input() {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		selectPiece();
	}

	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
		movePieceToMouse();
	}

	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
		placePiece();
	}
}