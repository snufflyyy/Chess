#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include "include/board.h"
#include "include/game.h"

// default values
int windowWidth = 600;
int windowHeight = 600;
float borderThinkness = 20; // the border around the chess board in pixels
float tileScale = 70;

// colors (change as you please!)
const Color borderColor = {96, 92, 92, 255};
const Color lightTileColor = {212, 212, 212, 255};
const Color darkTileColor = {148, 148, 148, 255};

bool currentColor;

// used for window resizing
void getTileScale() {
    if (windowWidth < windowHeight) {
        tileScale = ((float) windowWidth / BOARDSIZE);
    } else {
        tileScale = ((float) windowHeight / BOARDSIZE);
    }

    tileScale -= borderThinkness / 4;
}

void setup() {
    InitWindow(windowWidth, windowHeight, "Chess");

    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetWindowState(FLAG_VSYNC_HINT);

    srand(time(NULL));
    currentColor = rand() % 2;

    SetWindowIcon(LoadImage("../assets/pieces/white/pawn.png"));

    getTileScale();

    createBoard();
    createPieces();
}

void resize() {
    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();

    // updates tile scale based on new window width and height
    getTileScale();

    // creates a board with the new tile scale
    createBoard();
    resizePieces();
}

void cleanUp() {
    cleanUpPieces();
}
