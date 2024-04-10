#include <raylib.h>
#include <stdio.h>

#include "include/game.h"
#include "include/board.h"
#include "include/piece.h"
#include "include/input.h"

int main() {
    setup();

    while (!WindowShouldClose()) {
        input();
        
        BeginDrawing();
            ClearBackground(BLACK);
            drawBoard();
            drawPieces();
        EndDrawing();
    }

    pieceCleanUp();
    CloseWindow();

    return 0;
}