#ifndef CHESS_VARIABLES_H
#define CHESS_VARIABLES_H

#include <stdbool.h>

#define WINDOWWIDTH 800 
#define WINDOWHEIGHT 800

// finds the correct tile size based on the
// window sizes listed above
#if WINDOWWIDTH < WINDOWHEIGHT
    #define TILESIZE (WINDOWWIDTH / 8)
#else
    #define TILESIZE (WINDOWHEIGHT / 8)
#endif

extern bool color;

#endif //CHESS_VARIABLES_H
