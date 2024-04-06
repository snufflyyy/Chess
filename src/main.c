#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "include/variables.h"
#include "include/board.h"
#include "include/piece.h"
#include "include/input.h"

int main() {
    // set up (maybe move to another file)
    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "Chess");

    SetWindowState(FLAG_VSYNC_HINT);
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    srand(time(NULL));

    // false = black and true = white
    color = (rand() % 2 == 0) ? false : true;

    createBoard();
    createPieces();

    while (!WindowShouldClose()) {
        input();

        BeginDrawing();
            ClearBackground(BLACK);
            drawBoard();
            drawPieces();
            DrawFPS(10, 10);
        EndDrawing();
    }

    boardCleanUp();

    return 0;
}