#include <raylib.h>
#include <stdio.h>

#include "include/game.h"
#include "include/board.h"
#include "include/piece.h"
#include "include/input.h"

int main() {
    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "Chess");
    SetWindowState(FLAG_VSYNC_HINT);

    // first player will be white
    color = true;

    createBoard();
    createPieces();

    while (!WindowShouldClose()) {
        input();
        
        BeginDrawing();
            ClearBackground(BLACK);
            drawBoard();
            drawPieces();
        EndDrawing();
    }

    pieceCleanUp();

    return 0;
}