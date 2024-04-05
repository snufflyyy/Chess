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
    ConfigFlags(FLAG_MSAA_4X_HINT);
    ConfigFlags(FLAG_VSYNC_HINT);
    SetTargetFPS(60);
    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "Chess");

    srand(time(NULL));

    // false = black and true = white
    bool color = (rand() % 2 == 0) ? false : true;

    createBoard(color);
    createPieces();

    while (!WindowShouldClose()) {
        input(color);

        BeginDrawing();
            ClearBackground(BLACK);
            drawBoard();
            drawPieces();
        EndDrawing();
    }

    boardCleanUp();

    return 0;
}