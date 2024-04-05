#ifndef CHESS_VARIABLES_H
#define CHESS_VARIABLES_H

#define WINDOWWIDTH 600
#define WINDOWHEIGHT 600

// finds the correct tile size based on the
// window sizes listed above
#if WINDOWWIDTH < WINDOWHEIGHT
    #define TILESIZE (WINDOWWIDTH / 8)
#else
    #define TILESIZE (WINDOWHEIGHT / 8)
#endif

#endif //CHESS_VARIABLES_H
