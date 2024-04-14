#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#define BOARDSIZE 8

extern int windowWidth;
extern int windowHeight;
extern float borderThinkness;
extern float tileScale;

extern const Color borderColor;
extern const Color lightTileColor;
extern const Color darkTileColor;

// true is white and false is black
extern bool currentColor;

void setup();
void resize();
void cleanUp();

#endif
