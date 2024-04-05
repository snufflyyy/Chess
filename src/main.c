#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WINDOWWIDTH 800
#define WINDOWHEIGHT 800

#if WINDOWWIDTH < WINDOWHEIGHT
    #define TILESIZE (WINDOWWIDTH / 8)
#else
    #define TILESIZE (WINDOWHEIGHT / 8)
#endif    

const Color whiteColor = {212, 212, 212, 255};
const Color blackColor = {148, 148, 148, 255};

typedef enum {
    NONE,
    PAWN,
    BISHOP,
    KNIGHT,
    ROOK,
    QUEEN,
    KING
} PieceType;

typedef struct {
    Rectangle rectangle;
    PieceType type;
    Texture2D texture;
    bool color;
} Piece;

typedef struct {
    Piece piece;
    Rectangle rectangle;
    Color color;
} Tile;

// false = black and true = white
bool color;
Tile chessBoard[8][8];

// creates the game board
void createBoard() {
    bool isWhite = color;

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            chessBoard[x][y].rectangle = (Rectangle) {(float) x * TILESIZE, (float) y * TILESIZE, TILESIZE, TILESIZE};
            chessBoard[x][y].piece.rectangle = chessBoard[x][y].rectangle;

            if (isWhite) {
                chessBoard[x][y].color = whiteColor;
                isWhite = false;
            } else {
                chessBoard[x][y].color = blackColor;
                isWhite = true;
            }
        }
        isWhite = !isWhite;
    }
}

void createPieces() {
    Image whitePawn = LoadImage("../assets/pieces/white/pawn.png");
    Image blackPawn = LoadImage("../assets/pieces/black/pawn.png");

    ImageResize(&whitePawn, TILESIZE, TILESIZE);
    ImageResize(&blackPawn, TILESIZE, TILESIZE);

    for (int x = 0; x < 8; x++) {
        // black
        if (color == false) {
            // white pawns
            chessBoard[x][6].piece.type = PAWN;
            chessBoard[x][6].piece.color = true;
            chessBoard[x][6].piece.texture = LoadTextureFromImage(whitePawn);

            // black pawns
            chessBoard[x][1].piece.type = PAWN;
            chessBoard[x][1].piece.color = false;
            chessBoard[x][1].piece.texture = LoadTextureFromImage(blackPawn);
        } else { // white
            // black pawns
            chessBoard[x][6].piece.type = PAWN;
            chessBoard[x][6].piece.color = false;
            chessBoard[x][6].piece.texture = LoadTextureFromImage(blackPawn);

            // white pawns
            chessBoard[x][1].piece.type = PAWN;
            chessBoard[x][1].piece.color = true;
            chessBoard[x][1].piece.texture = LoadTextureFromImage(whitePawn);
        }
    }

    // clean up
    UnloadImage(whitePawn);
    UnloadImage(blackPawn);
}

void input() {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) 
                && CheckCollisionPointRec(GetMousePosition(), chessBoard[x][y].piece.rectangle) 
                && chessBoard[x][y].piece.type != NONE
                && chessBoard[x][y].piece.color == color) 
            {

            }
        }
    }
}

int main() {
    ConfigFlags(FLAG_MSAA_4X_HINT);
    ConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(WINDOWWIDTH, WINDOWHEIGHT, "Chess");

    srand(time(NULL));

    if (rand() % 2 == 0) {
        color = false;
    } else {
        color = true;
    }

    createBoard();
    createPieces();

    while (!WindowShouldClose()) {
        input();

        BeginDrawing();
            ClearBackground(BLACK);

            for (int x = 0; x < 8; x++) {
                for (int y = 0; y < 8; y++) {
                    DrawRectangleRec(chessBoard[x][y].rectangle, chessBoard[x][y].color);
                    if (chessBoard[x][y].piece.type != NONE) {
                        DrawTexture(
                            chessBoard[x][y].piece.texture,
                            chessBoard[x][y].rectangle.x, 
                            chessBoard[x][y].rectangle.y, 
                            WHITE
                        );
                    }
                }
            }

        EndDrawing();
    }

    // clean up
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            UnloadTexture(chessBoard[x][y].piece.texture);
        }
    }

    return 0;
}