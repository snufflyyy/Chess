#include "include/game.h"
#include <stdlib.h>
#include <time.h>
#include <raylib.h>

bool color;

bool isWhiteCheck = false;
bool isBlackCheck = false;

void setup() {
    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "Chess");
    SetWindowState(FLAG_VSYNC_HINT);

    srand(time(NULL));

    // first player will be white
    color = rand() % 2;

    createBoard();
    createPieces();
}