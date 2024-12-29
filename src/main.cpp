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

int main() {
    // Initialization
    SetConfigFlags(FLAG_MSAA_4X_HINT);  // Enable 4x antialiasing
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Collision Test");

    SetTargetFPS(FPS);
    // Main game loop
    while (!WindowShouldClose()) {
        // Drawing
        BeginDrawing();
        {
            ClearBackground(RAYWHITE);
            // Visual feedback when mouse is over ball
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}