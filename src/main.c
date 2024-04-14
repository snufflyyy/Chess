#include <stdio.h>

#include <raylib.h>

#include "include/game.h"
#include "include/board.h"
#include "include/input.h"

int main() {
    setup();

    while (!WindowShouldClose()) {
        if (IsWindowResized()) {
            resize();
        }

        //input();

        // debug
        if (IsKeyPressed(KEY_R)) {
            rotateBoard();
        }

        BeginDrawing();
            ClearBackground(borderColor);
            drawBoard();
            drawPieces();
            drawLetters();
            drawNumbers();
        EndDrawing();
    }

    cleanUp();
    CloseWindow();
    return 0;
}