#include <raylib.h>
#include <math.h>
#include "objects.h"
//------------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------------
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 650;
const int FPS = 60;            // Frames per Second

//------------------------------------------------------------------------------------
// Main program
//------------------------------------------------------------------------------------

int main(void) {
    // Initialization
    SetConfigFlags(FLAG_MSAA_4X_HINT);  // Enable 4x antialiasing
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Collision Test");

    RectangleObject r1({500, 500}, {200, 200}, BLACK);
    RectangleObject r2({300, 400}, {100, 100}, BLACK);
    r1.angle = 30;
    r2.angle = 60;

    SetTargetFPS(FPS);
    // Main game loop
    while (!WindowShouldClose()) {
        r1.update();
        r2.update();
        // Drawing
        BeginDrawing();
        {
            ClearBackground(RAYWHITE);
            r1.checkCollision({});
            r2.checkCollision({});
            r1.drawBorders();
            r2.drawBorders();
            // Visual feedback when mouse is over ball
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}