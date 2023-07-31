#include "/opt/homebrew/Cellar/raylib/4.5.0/include/raylib.h"
#include <iostream>
#include <unistd.h> 
#include <cstdlib>
#include <ctime>
#include <cmath>

//Compile code with g++ zergrush.cpp -o zergrush -I/opt/homebrew/Cellar/raylib/4.5.0/include -L/opt/homebrew/Cellar/raylib/4.5.0/lib -lraylib -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
//Run with ./zergrush


int main(){

    //Colors for the game
    const Color BGBLACK = {0, 0, 0, 255};

    // Initialize the window and set the frame rate
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Zergas Rushas");
    SetTargetFPS(60);
    ClearBackground(BGBLACK);



    // Main game loop
    while (!WindowShouldClose())
    {

        if (IsKeyPressed(KEY_SPACE)) {
            CloseWindow(); // Close the window when space bar is pressed
        }


        

        // Clear the screen and draw a circle in the center
        BeginDrawing();

        EndDrawing();
    }


    return 0;
}